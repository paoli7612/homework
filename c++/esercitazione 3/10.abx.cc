#include <iostream>

using namespace std;

/*
    Programma che chiede due numeri interni e dica
    se il terzo numero inserito sta dentro a quel intervallo
*/

int main(int argc, char** argv){

    int a, b, x;

    cout << "Inserisci due numeri interi A e B: ";
    cin >> a >> b;

    cout << "Inserisci un terzo numero x:";
    cin >> x;

    if ((a <= x) && (x <= b))
        cout << "X è dentro al intervallo di A e B" << endl;

    return 0;
}