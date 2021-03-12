#include <iostream>

using namespace std ;

/* Programma calcolo MCD di due numeri dati */

int main()
{
    int a, b;

    cout << "Inserisci due numeri: ";
    cin >> a >> b;

    while (b != 0){
        cout << a << " " << b << endl;
    	int resto = a%b;
	    a = b;
	    b = resto;
    }
    cout << "Il massimo comun divisore e' " << a << endl;

    return 0;
}