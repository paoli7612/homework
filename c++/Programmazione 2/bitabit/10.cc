#include <iostream>

/*Scrivere un programma che legga da tastiera un numero
naturale n, calcoli il piu' grande numero naturale pari i, tale che
i<=n, e stampi il risultato sullo schermo  (ovviamente, se n e' pari
i sara' uguale ad n, mentre, se n e' dispari, i sara' uguale a n-1).
Suggerimento: lavorare sulla configurazione di bit che rappresenta n.*/

using namespace std;

int main(int argc, char **argv)
{
    int n;
    cout << "Inserisci un numero naturale: ";
    cin >> n;

    cout << (n/2*2) << endl;

    return 0;
}