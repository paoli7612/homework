#include <iostream>

using namespace std;

/*
    Programma che legge un numero intero e stampa:
    il numero è non negativo, o il numero è negativo
*/

int main(int argc, char** argv){

    int n;

    cout << "Inserisci un numero intero: ";
    cin >> n;

    if (n >= 0)
        cout << "Il numero inserito è non nullo" << endl;
    else
        cout << "Il numero inserito è negativo" << endl;

    return 0;
}