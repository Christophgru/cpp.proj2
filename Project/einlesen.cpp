//
// Created by chris on 4/13/2022.
//

#include <cstdio>
#include <string>
#include "allefileseinlesenali.cpp"

using namespace std;

bool check_time(const string& time);

void oneinlesen(const char *pathueberwacherpfad, testabbildung testarray[40]) {
    cout << "\n";
    testabbildung newtest = import_files_from_link(pathueberwacherpfad);
    bool check = true;
    for (int j = 0; j < 40; ++j) {
        if (newtest.getUhrzeit() == testarray[j].getUhrzeit()) {
            check = false;
            break;
        }
    }

    if (check_time(newtest.getUhrzeit())&&check) {

        for (int i = 0; i < 40; ++i) {
            if (testarray[i].getFilename().empty()) {
                testarray[i] = newtest;
                printf("Buchung von %s gespeichert", newtest.getEmail().data());
                break;
            }
        }
    } else {

        ofstream myfile(pathueberwacherpfad);
        if (myfile.is_open()) {
            myfile << newtest.getEmail() << "\n";
            myfile << newtest.getUhrzeit() << "\n";
            myfile << "Abgelehnt\n";
            myfile.close();
        } else cout << "Fehler";
    }
}


bool check_time(const string& time) {
    char *time2 = new char[time.length() + 1];
    strcpy(time2, time.c_str());
    if (time2[0] > '0' && time2[1] > '8' || time2[0] == '0' && time2[1] < '8' || time2[2] != ':' || time2[0] > '1' ||
        ((int(time2[3]) - 48) * 10 + (int(time2[4])) - 48) % 15 != 0) {
        delete[] time2;
        return false;
    }
    delete[] time2;
    return true;
}


