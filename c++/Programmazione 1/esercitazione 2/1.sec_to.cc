#include <iostream>

using namespace std;

int main(int argc, char** argv){

    int n;

    cout << "Inserisci un numero intero: ";
    cin >> n;

    cout << n/60 << ":" << n%60 << endl;

    return 0;
}