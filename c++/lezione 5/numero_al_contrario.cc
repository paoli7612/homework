#include <iostream>

using namespace std;

/*
    Leggere da stin un numero intero positivo, che
    si assume essere compreso tra 100 e 999.
    stamparlo al contrario
    445 -> 545
    290 -> 092
    ...
*/

int main(int argc, char** argv){

    int n;
    cout << "Inserisci un numero intero tra 100 e 999" << endl;
    cin >> n;

    cout << n%10 << (n%100)/10 << n/100 << endl;

    return 0;
}
