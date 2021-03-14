#include <iostream>

using namespace std;

int main(int argc, char** argv){

    int a, b, x;
    cout << "Inserisci i valori di a e b" << endl;
    cin >> a >> b;

    cout << "Inserisci il valore di x" << endl;
    cin >> x;

    cout << ((a<=x) && (x<=b)) << endl;

    return 0;
}