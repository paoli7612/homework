#include <iostream>

using namespace std;

/*
    La consegna da solo il nome del sorgente.
    si supponde la creazione di un programma che, dati due numeri interi,
    ci dica quale è un multiplo dell'altro; altrimenti non dica nulla

    compreso anche lo 0
*/


int main()
{
    int a, b;
    cout << "Inserisci 2 numeri interi" << endl;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;
    if ((a * b) == 0)
        cout << "Rilevato almeno uno 0. Il programma non può continuare" << endl;
    else {
        if ((a > b) && (a%b == 0))
            cout << "A è un multiplo di B";
        else if ((a < b) && (b%a == 0))
            cout << "B è un multiplo di A";    
        else if (a%b == 0)
            cout << "A e B sono uguali";        
    }
    cout << endl;
}