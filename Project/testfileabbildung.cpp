//
// Created by chris on 4/14/2022.
//
#import <string>
using namespace std;


class testabbildung {
    string email;
    string uhrzeit;//hh:mm
    int ergebnis;
    string filename;

public:
    testabbildung(const char* email="",const char *uhrzeit="", const char *filename="") : email(email), uhrzeit(uhrzeit),
                                                                               filename(filename) {}

    enum ergebnistypen {
        positiv, negativ, abgelehnt
    };

    void setErgebnis(int ergebnis) {
        testabbildung::ergebnis = ergebnis;
    }

    const string &getEmail() const {
        return email;
    }

    const string &getFilename() const {
        return filename;
    }
};