//
// Created by chris on 4/13/2022.
//

#include <cstdio>
#include "testfileabbildung.cpp"

void onentfernt(const char *pathueberwacherpfad, testabbildung testarray[40]) {
    printf("entfernt\n");
    //todo: durchsuche das array in der main nach einem test mit dem pfad, dieses entfernen und durch ein anonymes
    // element ersetzten
    for (int i = 0; i < sizeof(testarray) / sizeof(testarray[0]); ++i) {
        if (testarray[i].getFilename() == pathueberwacherpfad) {
            testabbildung empty = testabbildung();
            testarray[i] = empty;
        }
    }
}