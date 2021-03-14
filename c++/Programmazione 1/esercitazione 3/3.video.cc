#include <iostream>

using namespace std;

int main(int argc, char** argv){

    int a, b, c;

    cout << "Inserisci 3 valori numerici" << endl;
    cin >> a >> b >> c;

    cout << "(" << a << "<" << b << ") o (" << a << "<" << c << "):";
    cout << ((a<b) || (a<c)) << endl;

    return 0;
}