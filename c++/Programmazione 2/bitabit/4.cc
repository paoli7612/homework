#include <cmath>
#include <iostream>

using namespace std;

/* Scrivere un programma che legga da tastiera due numeri
naturali n ed i, effettui la divisione intera del numero n per 2^i
senza utilizzare l'operatore divisione, e stampi il risultato sullo
schermo */

void cout_bin(int n)
{
    for (int i=6-1; i>=0; i--)
        cout << (n/((int)pow(2, i)))%2;
    cout << " ";
}

int main(int argc, char **argv)
{
    int n, i;
    cout << "Inserisci due numeri naturali n e i: ";
    cin >> n >> i;

    cout << n << "/" << (1<<i) << endl;

    cout_bin(n);
    cout << endl;
    cout_bin(1<<i);
    cout << endl;
    cout << (n>>i) << endl; 

}