#include <iostream>

using namespace std;

/*
    Scrivere un programma che legga un intero n
        finche il numero inserito non è compreso tra 0 e 10
    
    Chiede n numeri interi positivi e ne calcola la somma e il valore massimo
        (prima con for poi senza)

    L'inserimento di un valore nullo o negativo interrompe la sequenza
*/

int main()
{

    int n;
    int MINIMO = 0;
    int MASSIMO = 10;
    do {
        cout << "Inserisci n:";
        cin >> n;
    } while ((n <= 0) || (n >= 10));


    int m = 0, s = 0, p;
    for (int i=0; i<n; i++){
        cout << "Numero: ";
        cin >> p;
        if (p <= 0)
            break;
        if (p > m)
            m = p;
        s += p;
    }

    cout << "Massimo: " << m << endl;
    cout << "Somma: " << s << endl;

    return 0;
}