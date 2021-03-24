#include <iostream>

/*
Scrivere un programma che legga da tastiera un numero
naturale n, calcoli il piu' piccolo numero naturale dispari i, tale
che i>=n, e stampi il risultato sullo schermo.  (ovviamente, se n e'
dispari i sara' uguale ad n, mentre, se n e' pari, i sara' uguale a
n+1) 
*/

using namespace std;

int main(int argc, char **argv)
{

    int n;
    cout << "Inserisci il numero naturale n: ";
    cin >> n;

    cout << (n | 1) << endl;

    return 0;
}