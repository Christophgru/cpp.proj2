#include <iostream>
#include "string"
#include <fstream>
using namespace std;
string final[40];
int counter;

class Kunde{       // Probeklasse
public:
    bool Testergebnis;
    string Email;
    string Uhrzeit;
};
Kunde probearray[40];

void full() //array füllen zum testen
{
    for(int q=0; q<40; q++)
    {
        Kunde Hallo;
        Hallo.Email="Moin";
        if (q%2 == 0)
        {
            Hallo.Testergebnis=true;
        }
        else
        {
            Hallo.Testergebnis=false;
        }
        probearray[q]=Hallo;
    }
}
void sort() //die eigentliche methode (schauen ob ergebnis positiv ist und dann in zwischen array speichern
{
    for (int i = 0; i < 40; ++i)
    {
        if (probearray[i].Testergebnis == true)
        {
            final[counter]=probearray[i].Email;
            counter++;
        }

    }

}
void write() //final array in txt schreiben
{
    string filename("Ministerium.txt");
    fstream file_out;

    file_out.open(filename, std::ios_base::out);
    if (!file_out.is_open()) {
        cout << "failed to open " << filename << '\n';
    } else {
        for (int i = 0; i < counter; ++i) {
            file_out << final[i]<<endl;
        }
    }
}
int main() { //main zum testen vom programm
    full();
    sort();
    write();
    return 0;
}
