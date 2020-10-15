#include <iostream>

using namespace std;

/*
    Leggere da stin un numero intero positivo, che
    si assume essere compreso tra 100 e 999.
    stamparlo al contrario
    445 -> 545
    290 -> 092
    ...
    (il numero deve essere salvato in una nuova variabile intera)
    (non basta stamparlo al contrario)
*/

int main(int argc, char** argv){

    int n;
    cout << "Inserisci un numero intero tra 100 e 999" << endl;
    cin >> n;

    int r = (n%10)*100 + ((n%100)/10)*10 + (n/100);

    cout << (char)(48*(r<100)) << (char)(48*(r<10)) << r << endl;

    return 0;
}
