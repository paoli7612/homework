#include <iostream>

using namespace std;

/*
    chieda un numero n e stampa un quadrato di cancelletti n per n
*/

int main()
{
    int n;
    cin >> n;

    for (int y=0; y<n; y++){
        for (int x=0; x<n; x++)
            cout << " # ";
        cout << endl;
    }
}