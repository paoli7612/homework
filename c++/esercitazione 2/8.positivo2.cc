#include <iostream>
#include <stdlib.h>

using namespace std;

/*
    Chiedi un numero intero e stampa 1 se è positivo,
    altrimenti stampa 0
*/


int main(int argc, char** argv){

    int a;
    
    cout << "Inserisci un numero intero: ";
    cin >> a;

    cout << (a/abs(a)+1)/2 << endl;

    return 0;
}