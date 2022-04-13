//
// Created by chris on 4/13/2022.
//https://tutorialink.com/cpp/array-of-objects-in-cpp.cpp#:~:text=The%20array%20of%20type%20class,any%20built%2Din%20data%20type.
//

#include <iostream>

class MyClass {
    int x;
public:
    void setX(int i) { x = i; }

    int getX() { return x; }
};

void main() {
    MyClass obs[4];
    int i;

    for (i = 0; i < 4; i++)
        obs[i].setX(i);

    for (i = 0; i < 4; i++)
        cout << "obs[" << i << "].getX(): " << obs[i].getX() << "\n";

    getch();
}