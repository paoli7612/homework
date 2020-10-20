#include <iostream>

using namespace std;

/*
    L'utente inserisce due operanti interi
    poi immette il numero di un operatore
    il programma stampa il risultato 
*/

int main()
{

    int a, b;
    cout << "Inserisci due operandi interi" << endl;
    cin >> a >> b;

    cout << "\t1) +\n\t2) - \n\t3) x\n\t4) :" << endl;;

    int op, r;
    cin >> op;
    switch (op)
    {
    case 1:
        r = a + b;
        break;
    case 2:
        r = a - b;
        break;
    case 3:
        r = a * b;
        break;
    case 4:
        r = a / b;
        break;
    }
    cout << "Il risultato è " << r;
    if (op == 4)
        cout << " con il resto di " << a%b;
    cout << endl;

    return 0;
}