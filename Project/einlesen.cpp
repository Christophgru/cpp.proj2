#include "stdio.h"
#include "string"
#include <iostream>
using namespace std;
string dawdwa[2];
void ausgabe(string email)
{
    std::cout<< email;
}
void einlesen(){
    int counter;
    char dateiname2[] = "musterdatei_testbuchung.txt";
    char inhalt[] = "";
    FILE *datei2;
    datei2 = fopen(dateiname2, "r");
    if(datei2 != NULL){
        while(feof(datei2) == NULL){
            fgets(inhalt, 50, datei2);
            /*printf("%s", inhalt);*/
            dawdwa[counter] = inhalt;
            counter++;
        }
    }
    for(int i=0; i<2;i++)
    {
        ausgabe(dawdwa[i]);
    }
}

int main(void){
    einlesen();
}