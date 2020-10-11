#include <iostream>

using namespace std;

/*
    Programma che legge un numero intero e stampa:
    il numero è positivo, se lo è
*/

int main(int argc, char** argv){

    int n;

    cout << "Inserisci un numero intero: ";
    cin >> n;

    if (n > 0)
        cout << "Il numero inserito è positivo";

    return 0;
}