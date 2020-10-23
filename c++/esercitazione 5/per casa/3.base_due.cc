#include <iostream>

using namespace std;

/*
    converti un numero da decimale a binario
*/

int main()
{
    const int base = 2;

    int n, bit;
    cout << "Inserisci un numero intero: ";
    cin >> n;

    cout << (n-(n%2))%4;

    cout << n%2;

    /* REVERSE
    int resto = n;

    do
    {
        cout << resto % 2;
        resto = resto/2;
    } while (resto > 0);
    */
    cout << endl;
    

    return 0;
}