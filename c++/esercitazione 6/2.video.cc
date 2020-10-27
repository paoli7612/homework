#include <iostream>

using namespace std;

/*
    Programma calcolo fattoriale
*/

int fattoriale(int n){
    if (n < 2)
        return n;
    else
        return n * fattoriale(n-1);
}

int main()
{
    int n;
    cout << "Inserisci un numero intero: ";
    cin >> n;

    if (n>14)
        cout << "OVERFLOW" << endl;
    else
        cout << "il fattoriale di " << n << " è " << fattoriale(n) << endl;

    /*
        Se viene richiesto il fattoriale di un numero superiore a 14 andiamo in overflow
    */

    return 0;
}