
#include <iostream>

using namespace std;
/* Scrivere un programma che legge da tastiera due numeri
naturali n ed i, moltiplica il numero n per 2^i senza utilizzare
l'operatore moltiplicazione, e stampa il risultato sullo schermo */

int main(int argc, char **argv)
{
    int n, m;
    cout << "Inserisci due numeri naturali n e m: ";
    cin >> n >> m;

    cout << (n<<m) << endl; 

}