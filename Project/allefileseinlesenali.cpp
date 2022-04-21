//
// Created by chris on 4/14/2022.
//
#include <string>
#include <iostream>
#include <fstream>
#import "testfileabbildung.cpp"

using namespace std;
testabbildung import_files_from_link(const char *pathueberwacherpfad) {
    //todo: Ali : Lese Files aus, erstelle für jedes file ein testabbildung objekt, pack die ins array, gebe array zurück
    //befüllen

    string tmp[2];
    int i=0;
    fstream file;
    file.open(pathueberwacherpfad, ios::in);
    string zeile;
    while(!file.eof()){
        getline(file, zeile);
        tmp[i] = zeile;
        i++;
        if(i>=2){
            break;
        }
    }
    testabbildung new_file=testabbildung(tmp[0].data(),tmp[1].data(),pathueberwacherpfad);
    return new_file;
}