//
// Created by chris on 4/10/2022.
//

#include <windows.h>
#include <cstdint>
#include <cstdio>
#include <cassert>
#include <iostream>
using namespace std;
using std::cout;


string getPath(char **argv)
{
    string path(argv[0]);
    uint8_t pathsize = path.size();
    int i = pathsize-1;
    char c = path.at(i);
    while(c != '\\')
    {

        path.pop_back();
        i--;
        c = path.at(i);
    }
    string datei = {"dump_data"};
    path = path + datei;
    return path;
}
int main(int argc, char **argv) {
    string i = getPath(argv);
    cout << i;
}