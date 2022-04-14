//
// Created by chris on 4/13/2022.
//
//#todo: ali

#include <cstdio>
#include "testfileabbildung.cpp"
#include "allefileseinlesenali.cpp"

void oneinlesen(char* pathueberwacherpfad,test testarray[40]) {
    test *frompath =import_files_from_link(pathueberwacherpfad);
    printf("eingelesen\n");
}