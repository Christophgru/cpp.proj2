//
// Created by chris on 4/10/2022.
//

#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <csignal>

using namespace std;

// Define the function to be called when ctrl-c (SIGINT) is sent to process
void signal_callback_handler(int signum) {
    cout << "Caught signal " << signum << endl;
    // Terminate program
    exit(signum);
}

int main() {
    // Register signal and signal handler
    signal(SIGINT, signal_callback_handler);
    for (int i = 0; i < 500; ++i) {

        cout << "Program processing..." << endl;
        sleep(1);
    }
    return EXIT_SUCCESS;
}