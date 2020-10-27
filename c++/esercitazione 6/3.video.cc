#include <iostream>

using namespace std;

/*
    Funzione che prende in ingresso un numero e ci dice se è ottenibile
    come prodotto di due interi

    Funzione che prende in ingresso due numeri che: se il primo è ottenibile
    com quadrato del secondo più il quadrato di un altro intero(positivo), ci ritorna
    il terzo numero altrimenti ritorna -1 
*/

bool rad(int n){
    for (int i=2; i<n; i++)
        if (i*i == n)
            return true;
    return false;
}
int somma_di_quadrati(int n, int i){
    for (int a=0; a<n; a++)
        if (a*a + i*i == n)
            return a;
    return -1;
}

int main()
{
    int n;

    cout << "Inserisci un numero intero" << endl;
    cin >> n;

    if (rad(n))
        cout << n << " puo essere riscritto come quadrato due un altro intero" << endl;
    else 
        cout << "La radice di " << n << " non è un numero intero" << endl;


    int i;
    cout << "Controlliamo se è la somma di due quadrati, inserisci un intero: ";
    cin >> i;
    int s = somma_di_quadrati(n, i);
    if (s == -1)
        cout << n << " non può essere espresso come somma del quadrato di " << i << " e del quadrato di un altro intero" << endl;
    else
        cout << n << " è uguale alla somma del quadrato di " << i << " e del quadrato di " << s << endl;
}