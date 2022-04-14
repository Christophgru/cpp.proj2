//
// Created by chris on 4/10/2022.
//

#include <windows.h>
#include <cstdint>
#include <cstdio>
#include <cassert>
#include "einlesen.cpp"
#include "entfernt.cpp"
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <csignal>
#include "exit.cpp"
#include "testfileabbildung.cpp"

using namespace std;


bool bigloop = true;
bool smallloop = true;
test testarray[40];
char *path = R"(C:\Users\chris\OneDrive\Dokumente\DHBW\Programmieren\c_cpp\kleines_rumprobiere\Projekt2\Project\dump_data)"; // Pfad zum ueberwachten Verzeichnis.



// Define the function to be called when ctrl-c (SIGINT) is sent to process
void signal_callback_handler(int signum) {
    cout << "Caught signal " << signum << endl;
    // Terminate program
    onexit(path,testarray);
    bigloop = false;
    smallloop = false;
    exit(signum);
}


int main() {
    signal(SIGINT, signal_callback_handler);
    // Handle fuer das Verzeichnis
    HANDLE file = CreateFile(path,
                             FILE_LIST_DIRECTORY,
                             FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                             NULL,
                             OPEN_EXISTING,
                             FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED,
                             NULL);
    assert(file != INVALID_HANDLE_VALUE);

    // Event erstellen
    OVERLAPPED overlapped;
    overlapped.hEvent = CreateEvent(NULL, FALSE, 0, NULL);

    // Speicher holen, hier auf dem Stack
    uint8_t change_buf[1024];

    // den Buffer, die Notifications die abgeholt werden und das Event verknÃ¼pfen
    BOOL success = ReadDirectoryChangesW(
            file, change_buf, 1024, TRUE,
            FILE_NOTIFY_CHANGE_FILE_NAME |
            FILE_NOTIFY_CHANGE_DIR_NAME |
            FILE_NOTIFY_CHANGE_LAST_WRITE,
            NULL, &overlapped, NULL);

    // es geht los
    printf("watching %s for changes...\n", path);

    while (bigloop) {
        DWORD result = WaitForSingleObject(overlapped.hEvent, 0);

        if (result == WAIT_OBJECT_0) {
            DWORD bytes_transferred;
            GetOverlappedResult(file, &overlapped, &bytes_transferred, FALSE);

            FILE_NOTIFY_INFORMATION *event = (FILE_NOTIFY_INFORMATION *) change_buf;
            while (smallloop) {
                DWORD name_len = event->FileNameLength / sizeof(wchar_t);

                switch (event->Action) {
                    case FILE_ACTION_ADDED: {
                        wprintf(L"       Added: %.*s\n", name_len, event->FileName);
                        oneinlesen(path,testarray);
                    }
                        break;

                    case FILE_ACTION_REMOVED: {
                        wprintf(L"     Removed: %.*s\n", name_len, event->FileName);
                        onentfernt(path,testarray);
                    }
                        break;

                    case FILE_ACTION_MODIFIED: {
                        wprintf(L"    Modified: %.*s\n", name_len, event->FileName);
                    }
                        break;

                    case FILE_ACTION_RENAMED_OLD_NAME: {
                        wprintf(L"Renamed from: %.*s\n", name_len, event->FileName);
                    }
                        break;

                    case FILE_ACTION_RENAMED_NEW_NAME: {
                        wprintf(L"          to: %.*s\n", name_len, event->FileName);
                    }
                        break;

                    default: {
                        printf("Unknown action!\n");
                    }
                        break;
                }

                // Are there more events to handle?
                if (event->NextEntryOffset) {
                    *((uint8_t **) &event) += event->NextEntryOffset;
                } else {
                    break;
                }
            }

            // Queue the next event
            BOOL success = ReadDirectoryChangesW(
                    file, change_buf, 1024, TRUE,
                    FILE_NOTIFY_CHANGE_FILE_NAME |
                    FILE_NOTIFY_CHANGE_DIR_NAME |
                    FILE_NOTIFY_CHANGE_LAST_WRITE,
                    NULL, &overlapped, NULL);

        }

        // Do other loop stuff here...
    }
}
