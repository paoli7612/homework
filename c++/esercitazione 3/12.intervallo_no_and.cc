#include <iostream>

using namespace std;

/*
    Scrivere un programma che definisca e inizializzi due costanti intere
    a e b, poi legga in ingresso un numero intero e scriva un messaggio
    se il numero è compreso nell'intervallo [a, b]

    Non usare and
*/

int main()
{
    const int a = 10, b = 20;
    int n;
    cin >> n;
    if (a <= n)
        if (n <= b)
            cout << "Il numero è compreso nel intervallo (estremi compresi)" << endl;
}