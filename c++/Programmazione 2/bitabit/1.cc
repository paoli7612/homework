#include <iostream>

using namespace std;

/* Scrivere un programma che legga da tastiera un numero naturale n,
moltiplichi il numero per 2 senza utilizzare l'operatore di moltiplicazione
e stampi il risultato sullo schermo */

int main(int argc, char **argv)
{
    int n;
    cout << "Inserisci un numero naturale n: ";
    cin >> n;

    n = n<<1;

    cout << n << endl;
}