#include <iostream>

using namespace std;

/*
    Fattoriale

    SENZA RICORSIVITA
*/

int main()
{
    int n;
    cout << "Inserisci un numero intero positivo" << endl;
    cin >> n;

    int f = 1;

    for (int p=2; p<=n; p++)
        f *= p;

    cout << "Fattoriale: " << f << endl;

    return 0;
}