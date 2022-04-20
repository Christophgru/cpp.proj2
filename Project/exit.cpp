//
// Created by chris on 4/13/2022.
//

#include <cstdio>
#include "testfileabbildung.cpp"

void onexit(char* pathueberwacherpfad,test testarray[40]){
    printf("exit\n");
    //bsp zugriff
    testarray[5].setergebnis(test::positiv);
}