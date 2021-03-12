#include <iostream>

using namespace std;

/*
    Chiedi un numero intero e stampa 1 se il
    numero è pari, altrimenti stampa 0
*/

int main(int argc, char** argv){

    int n;

    cout << "Inserisci un numero: ";
    cin >> n;

    cout << (n+1)%2 << endl;

    return 0;
}