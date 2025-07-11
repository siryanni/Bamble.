#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int geld = 100;
    int einsatz, tipp, zufallszahl;

    cout << "Willkommen im Mini-Casino!" << endl;

    while (geld > 0) {
        cout << "\nAktuelles Guthaben: " << geld << " Euro" << endl;
        cout << "Wie viel willst du setzen? (0 = beenden): ";
        cin >> einsatz;

        if (einsatz == 0) break;
        if (einsatz > geld || einsatz < 0) {
            cout << "Ungueltiger Einsatz." << endl;
            continue;
        }

        cout << "Tipp eine Zahl zwischen 1 und 5: ";
        cin >> tipp;

        if (tipp < 1 || tipp > 5) {
            cout << "Ungueltige Zahl." << endl;
            continue;
        }

        zufallszahl = rand() % 5 + 1;
        cout << "Gezogene Zahl: " << zufallszahl << endl;

        if (tipp == zufallszahl) {
            cout << "Gewonnen! Du bekommst " << einsatz * 5 << " Euro." << endl;
            geld += einsatz * 4; // Einsatz zurück + 4x Gewinn
        }
        else {
            cout << "Verloren. Du verlierst " << einsatz << " Euro." << endl;
            geld -= einsatz;
        }
    }

    cout << "\nSpiel beendet. Endguthaben: " << geld << " Euro" << endl;
    return 0;
}



