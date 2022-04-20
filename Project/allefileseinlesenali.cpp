//
// Created by chris on 4/14/2022.
//
#include <string>
#import "testfileabbildung.cpp"
#import "main.cpp"
#include <iostream>
#include <fstream>
using namespace std;
string dawdwa[2];
testabbildung import_files_from_link(const char *pathueberwacherpfad, testabbildung arrayrueckgabe[40]) {
    //todo: Ali : Lese Files aus, erstelle für jedes file ein testabbildung objekt, pack die ins array, gebe array zurück
    //befüllen
    int counter;
    fstream file;
    file.open(pathueberwacherpfad, ios::in);
    string zeile;
    while(!file.eof()){
        getline(file, zeile);
        dawdwa[counter] = zeile;
        counter++;
    }
    testabbildung new_file=testabbildung(dawdwa[0].data(),dawdwa[1].data(),pathueberwacherpfad);
    return new_file;
}