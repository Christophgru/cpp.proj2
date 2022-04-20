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

char *pathtemp;
bool bigloop = true;
bool smallloop = true;
testabbildung testarray[40];


string buildpath(WCHAR name[1], char **argv, DWORD len);

string getPath(char **argv);

// Define the function to be called when ctrl-c (SIGINT) is sent to process
void signal_callback_handler(int signum) {
    cout << "Caught signal " << signum << endl;
    // Terminate program
    onexit(pathtemp, testarray);
    bigloop = false;
    smallloop = false;
    exit(signum);
}


int main(int argc, char **argv) {
    char filledpath[1024];
    string str = getPath(argv);
    const char *path = str.data(); // Pfad zum ueberwachten Verzeichnis.
    int len = str.length();
    for (int i = 0; i < len; ++i) {
        filledpath[i] = str.at(i);
    }
    pathtemp = filledpath;

    cout << path << endl;

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
                        string myfilefilepath = buildpath(event->FileName, argv, name_len);
                        printf("\n %s\n", myfilefilepath.data());
                        oneinlesen(myfilefilepath.data(), testarray);
                    }
                        break;

                    case FILE_ACTION_REMOVED: {
                        string myfilefilepath = buildpath(event->FileName, argv, name_len);
                        printf("\n %s\n", myfilefilepath.data());
                        onentfernt(myfilefilepath.data(), testarray);
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

string buildpath(WCHAR name[1], char **argv, DWORD len) {
    wstring your_wchar_in_ws(name);
    //string your_wchar_in_str(your_wchar_in_ws.begin(), your_wchar_in_ws.end());
    string mystring;
    for (int i = 0; i < len; ++i) {
        mystring.push_back(your_wchar_in_ws.at(i));
    }
    //const char* your_wchar_in_char =  your_wchar_in_str.c_str();
    string myfilefilepath = getPath(argv) + "\\" + mystring;
    return myfilefilepath;
}

string getPath(char **argv) {
    string path(argv[0]);
    uint8_t pathsize = path.size();
    int i = pathsize - 1;
    char c = path.at(i);
    while (c != '\\') {

        path.pop_back();
        i--;
        c = path.at(i);
    }
    string datei = {"dump_data"};
    path = path + datei;
    return path;
}
