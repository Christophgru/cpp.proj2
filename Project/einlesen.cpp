//
// Created by chris on 4/13/2022.
//

#include <cstdio>
#include "testfileabbildung.cpp"
#include "allefileseinlesenali.cpp"

bool check_time(const string &time);

void oneinlesen(const char *pathueberwacherpfad, testabbildung testarray[40]) {
    testabbildung newtest = import_files_from_link(pathueberwacherpfad);
    //todo: newtest auf uhrzeit prüfen unter Umständen ablehnen
    //todo: email prüfen
    //todo: wenn ein test fehlschlägt Eintrag "Abgelehnt/Anfrage ungültig" im file vornehmen
    //          sonst in array einfügen
    if (check_time(newtest.getUhrzeit())) {
        for (int i = 0; i < 40; ++i) {
            if (testarray[i].getFilename() == "") {
                testarray[i] = newtest;
                printf("Buchung von %s angekommen", newtest.getEmail().data());
                break;
            }
        }
    }
}

bool check_time(string time) {
    char *time2 = new char[time.length() + 1];
    strcpy(time2, time.c_str());
    if (time2[0] > '0' && time2[1] > '8' || time2[0] == '0' && time2[1] < '8' || time2[2] != ':' || time[0] > 1 ||
        ((int(time2[3]) - 48) * 10 + (int(time2[4])) - 48) % 15 != 0) {
        delete[] time2;
        return false;
    }
    delete[] time2;
    return true;
}
