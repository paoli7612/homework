/* 
 * Nella soluzione del seguente esercizio si utilizza l'istruzione
 * for. Se non l'avete ancora vista a lezione, utilizzate invece
 * l'istruzione while. Riscrivete poi il programma utilizzando
 * l'istruzione for una volta che l'avrete vista a lezione, e
 * confrontate la vostra con la soluzione riportata in questo file.
 *
 * Spesso per rappresentare (anche al variare del tempo) quale porzione di un 
 * certo lavoro è stata completata (o ad esempio quale frazione della carica 
 * massima è presente in una batteria) si utilizza una barra di lunghezza 
 * proporzionale a tale porzione (la barra ha/raggiunge la lunghezza massima 
 * se/quando l'intero lavoro è completato o la carica della batteria è massima).
 *
 * Scrivere un programma che legga da stdin un valore percentuale 
 * (in centesimi) e la lunghezza massima della barra con cui 
 * rappresentare tale percentuale (attenzione al numero massimo di colonne 
 * che si suppone siano disponibili sul terminale). Il programma stampa quindi sullo 
 * schermo la barra nel formato mostrato nei seguenti esempi
 *
 * Esempi:
 *
 * Inserire la percentuale (in centesimi), e la lunghezza della barra: 20 40
 *  --------------------------------------
 * |XXXXXXX                               |
 *  --------------------------------------
 *
 * Inserire la percentuale (in centesimi), e la lunghezza della barra: 100 30
 * ----------------------------
 *|XXXXXXXXXXXXXXXXXXXXXXXXXXXX|
 * ----------------------------
 *
*/

#include <iostream>

using namespace std;

int main()
{
    
    int n;
    cout << "Inserisci un numero intero: ";
    cin >> n;

    const int LEN = 20;

    cout << "-";
    for (int i=0; i<LEN; i++)
        cout << "-";
    cout << "-" << endl << "|" ;

    for (int i=0; i<20; i++)
        if (i*20 > 100*n)
            cout << "X";
        else cout << " ";
    cout << "|" << endl;

    for (int i=0; i<LEN; i++)
        cout << "-";
    cout << "--" << endl;
}