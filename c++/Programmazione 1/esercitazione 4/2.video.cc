#include <iostream>

using namespace std;

/*
    Scrivere un programa che chieda all'utente di scegliere tra le seguenti
    opzioni (di cui una ripetuta due volte) e stampi il nome dell'opzione scelta
    1. Opzione A
    2. Opzione B
    3. Opzione C    <-
    4. Opzione C    <-
    5. Opzione D
    >>>
        Scegli un opzione: n
        Hai scelto l'opzione L
    >>>
    "NON RIPETERE IL CODICE"
*/

int main()
{
    int n;
    cout << "Scegli un opzione: ";
    cin >> n;
    
    char L;

    switch (n)
    {
    case 1:
        L = 'A';
        break;
    case 2:
        L = 'B';
        break;
    case 3: case 4:
        L = 'C';
        break;
    case 5:
        L = 'D';
        break;
    default:
        cout << "Non hai scelto nessuna opzione" << endl;
        return 1; 
    }

    cout << "Hai scelto l'opzione " << L << endl;

    return 0;
}