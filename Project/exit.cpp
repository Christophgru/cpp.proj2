//
// Created by chris on 4/13/2022.
//

#include <cstdio>
#include <cstdlib>
#include <random>
#include <iostream>
#include <fstream>
#include "testfileabbildung.cpp"

using u32 = uint_least32_t;
using engine = std::mt19937;

void onexit(char *pathueberwacherpfad, testabbildung testarray[40]) {
    testabbildung pos_test[40];
    int count = 0;
    printf("exit\n");
    std::random_device os_seed;
    const u32 seed = os_seed();

    engine generator(seed);
    std::uniform_int_distribution<u32> distribute(0, 1);

    for (int i = 0; i < sizeof(testabbildung) / sizeof(testarray[0]); ++i) { //test oder testarray??
        if (distribute(generator)) {
            testarray[i].setErgebnis(testabbildung::negativ);
        } else {
            testarray[i].setErgebnis(testabbildung::positiv);
            pos_test[count] = testarray[i];
            count++;
        }
    }
    std::ofstream outfile ("pos_test.txt");
    for (int i = 0; i < sizeof(testabbildung)/ sizeof(pos_test[0]); ++i) {
        outfile << pos_test[i].getEmail() << std::endl;
    }
    outfile.close();

    //todo: steve absprache mit yangraf
}