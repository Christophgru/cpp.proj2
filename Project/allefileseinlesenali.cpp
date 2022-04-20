//
// Created by chris on 4/14/2022.
//
#include <string>
#import "testfileabbildung.cpp"
#import "main.cpp"

using namespace std;
string dawdwa[2];
testabbildung import_files_from_link(const char *pathueberwacherpfad, testabbildung arrayrueckgabe[40]) {
    //todo: Ali : Lese Files aus, erstelle für jedes file ein testabbildung objekt, pack die ins array, gebe array zurück
    //befüllen
    int counter;
    char inhalt[] = "";
    FILE *datei2;
    datei2 = fopen(pathueberwacherpfad, "r");
    if (datei2 != NULL) {
        while (feof(datei2) == NULL) {
            fgets(inhalt, 50, datei2);
            dawdwa[counter] = inhalt;
            counter++;
        }
    }
    testabbildung new_file=testabbildung(dawdwa[0].data(),dawdwa[1].data(),pathueberwacherpfad);
    return new_file;
}