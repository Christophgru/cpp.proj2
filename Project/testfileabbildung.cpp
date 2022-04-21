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
    enum ergebnistypen {
        tba, positiv, negativ, abgelehnt
    };

    void setErgebnis(int ergebnis_) {
        testabbildung::ergebnis = ergebnis_;
    testabbildung(const char *email = "", const char *uhrzeit = "", const char *filename = "", int ergebnis = tba)
            : email(email), uhrzeit(uhrzeit),
              filename(filename), ergebnis(ergebnis) {}

    }

    const string &getEmail() const {
        return email;
    }

    const string &getFilename() const {
        return filename;
    }

    const string &getUhrzeit() const {
        return uhrzeit;
    }

    int getErgebnis() const {
        return ergebnis;
    }
};