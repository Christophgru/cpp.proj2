//
// Created by chris on 4/14/2022.
//



class testabbildung {
    char email[40];
    char uhrzeit[5];//hh:mm
    int ergebnis;

public:
    enum ergebnistypen {
        positiv, negativ, abgelehnt
    };

    void setergebnis(ergebnistypen writeergebnis){
        ergebnis=writeergebnis;
    }

    const char *getEmail() const {
        return email;
    }

    const char *getUhrzeit() const {
        return uhrzeit;
    }

    int getErgebnis() const {
        return ergebnis;
    }

    void setErgebnis(int ergebnis) {
        testabbildung::ergebnis = ergebnis;
    }


};