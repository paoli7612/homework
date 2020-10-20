#include <iostream>

using namespace std;

/*
    La consegna da solo il nome del sorgente.
    si supponde la creazione di un programma che, dati 3 numeri interi
    da tastiera, ci dica se sono ordinati, e fino a che punto
*/

int main()
{
    int a, b, c;
    cout << "Inserisci 3 numeri interi" << endl;
    cin >> a >> b >> c;

    if ((a == b) || (b == c) || (a == c))
        cout << "I numeri non sono tutti diversi tra loro";
    else
    {
        if (a < b){
            cout << "i primi due numeri sono in ordine crescente";
            if (b < c)
                cout << " e anche il terzo";
        } else {
            cout << "i primi due numeri sono in ordine decrescente";
            if (b > c)
                cout << " e anche il terzo";
        }
    }
    cout << endl;
}