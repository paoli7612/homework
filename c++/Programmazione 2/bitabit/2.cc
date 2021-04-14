

#include <iostream>

using namespace std;

/* Scrivere un programma che legga da tastiera un numero naturale n e,
	se n e' dispari, stampi 1, altrimenti stampi 0 */

int main(int argc, char **argv)
{
    int n;
    cout << "Inserisci un numero naturale n: ";
    cin >> n;

    cout << (n&1) << endl;
}