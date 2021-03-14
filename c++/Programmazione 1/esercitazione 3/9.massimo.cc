#include <iostream>

using namespace std;

/*
    Scrivere un programma che chiede due numeri interi e
    stampa il numero maggiore (spiegando)
*/

int main(int argc, char** argv){

    int a, b;

    cout << "Inserisci due numeri interi" << endl;
    cin >> a >> b;

    if (a > b)
        cout << "Il valore maggiore è " << a << endl;
    else if (a < b)
        cout << "Il valore maggiore è " << b << endl;
    else
        cout << "I valori sono uguali" << endl;

    return 0;
}