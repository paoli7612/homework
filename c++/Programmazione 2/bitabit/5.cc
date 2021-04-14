#include <cmath>
#include <iostream>

using namespace std;

/* 
    Scrivere un programma che legga da tastiera due numeri naturali i e j. 
    Il programma stampi il valore di un numero naturale 
    z che ha la seguente rappresentazione binaria: 
    le j cifre meno significative di z (ossia quelle a partire dalla
    cifra piu' a destra) coincidono con le j cifre piu' significative 
    (ossia quelle a partire dalla cifra piu' a sinistra) della rappresentazione 
    binaria di i, mentre le restanti cifre sono a zero.

    Esempio. Supponiamo che i abbia la seguente rappresentazione binaria: 
    01011001 01001011 01001000 00100010  (supponendo che i numeri naturali
    siano rappresentati su 32 bit).
    Se j=4, allora il numero calcolato z avra' la seguente rappresentazione
    binaria: 00000000 00000000 00000000 00000101.
*/

void cout_bin(int n)
{
    for (int i=31; i>=0; i--)
    {  
        int j = (int)pow(2, i);
        cout << (n/j)%2;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    int i, j;
    cout << "Inserisci i due numeri naturali: ";
    cin >> i >> j;

    cout_bin(i);
    cout_bin(i>>(32-j));
}