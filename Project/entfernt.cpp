//
// Created by chris on 4/13/2022.
//

#include <cstdio>
#import "testfileabbildung.cpp"


void onentfernt(const char *pathueberwacherpfad, testabbildung testarray[40]) {
    printf("entfernt\n");
    for (int i = 0; i < 40; ++i) {
        if (testarray[i].getFilename() == pathueberwacherpfad) {
            testabbildung empty = testabbildung();
            printf("Buchung %s wurde entfernt",testarray[i].getEmail().data());
            testarray[i] = empty;
            break;
        }
    }
}