#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv){

    const char menu[] = 
        "1. Leggi codice promozione\n"
        "2. Inserisci prodotto\n"
        "3. Stampa prodotti\n"
        "4. Salva prodotti\n"
        "5. Carica prodotti\n"
        "6. Elimina codice prodotto\n"
        "7. Esci\n";

    bool running = true;
    while (running){

        cout << menu;

        int scelta;
        cin >> scelta;

        Codice codice;
        Pos posizione;

        switch (scelta){
            case 1: // Leggi codice posizione
                break;
            case 2: // Inserisci prodotto       
                break;
            case 3: // Stampa prodotti
                break;
            case 4: // Salva prodotti
                break;
            case 5: // Carica prodotti
                break;
            case 6: // Elimina codice prodotto
                break;
            case 7: // Esci
                break;
        }

    }

    return 0;
}
