#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int a, b;

    cout << "Inserisci i due valori interi" << endl;
    cin >> a >> b;

    cout << "Valore di " << a << "<" << b << ": " << (a<b) << endl;


    return 0;
}