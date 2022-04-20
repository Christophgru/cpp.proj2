//
// Created by chris on 4/13/2022.
//

#include <cstdio>
#include "testfileabbildung.cpp"
#include "allefileseinlesenali.cpp"

void oneinlesen(const char *pathueberwacherpfad, testabbildung testarray[40]) {
    testabbildung fileseinlesen[40];
    testabbildung newtest= import_files_from_link(pathueberwacherpfad, fileseinlesen);
    //todo: newtest auf uhrzeit prüfen unter Umständen ablehnen
    //todo: email prüfen
    //todo: wenn ein test fehlschlägt Eintrag "Abgelehnt/Anfrage ungültig" im file vornehmen
    //          sonst in array einfügen


}