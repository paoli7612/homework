#include <iostream>

using namespace std;

/*
    Scrivere un programma che definisca e inizializzi due costanti intere
    a e b, poi legga in ingresso due numeri interi c e i

    se c == 0
        programma stampa se i non è nel intervallo [a, b]
    else
        dice che non sono stati effettuati controlli

*/

int main()
{
    const int a = 10, b = 20;
    int i, c;
    cin >> i >> c;

    if (c)
    {
        if ((a > i) || (i > b))
            cout << "Il numero non è nel intervallo" << endl;
    }
    else 
    {
        cout << "non ho fatto nessun controllo" << endl;

    }
     

}