//
// Created by chris on 4/14/2022.
//



class test {
    char email[40];
    char uhrzeit[5];//hh:mm
    int ergebnis;

public:
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
        test::ergebnis = ergebnis;
    }

    enum ergebnistypen {
        positiv, negativ, abgelehnt
    };
};