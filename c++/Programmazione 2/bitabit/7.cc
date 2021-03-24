#include <iostream>
#include <cmath>

using namespace std;

/*
Scrivere un programma che legge da tastiera due numeri naturali k e j,
e ruota a destra di j posizioni la rappresentazione binaria del numero k.
-> La rotazione a destra di j posizioni di una configurazione di bit, si 
comporta come la traslazione (shift) a destra di j posizioni, eccetto il fatto
che, i j bit meno significativi di tale configurazione divengono i j bit piu' 
significativi della nuova configurazione (mentre, nel caso della traslazione 
i j bit meno significativi sarebbero stati buttati via).
*/

void cout_bin(unsigned int n)
{
    for (int i=31; i>=0; i--)
        cout << (n/((int)pow(2, i)))%2;
    cout << endl;
}


int main(int argc, char **argv)
{
    unsigned int k, j;
    cout << "Inserisci i numeri naturali k e j: ";
    cin >> k >> j;

    cout_bin(k);

    cout_bin((k>>j) | (k<<(32-j)));

    return 0;
}