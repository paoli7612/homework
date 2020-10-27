#include <iostream>

using namespace std;

/*
    Programma che stampi il massimo tra due interi letti in input

    Implementare calcolo mediante funzione

    Non usare funzioni di libreria
*/

int max(int a, int b){
    if (a >= b)
        return a;
    else // Cavicchioli non lo mette perche effettivamente non è necessario.. mi sembra pero che sia piu "leggibile" cosi ahahha
        return b;
}

int main()
{
    int a, b;
    cout << "Inserisci due numeri interi" << endl;

    cin >> a >> b;

    int m = max(a, b);

    cout << "Il massimo è " << m << endl; 

    return 0;
}