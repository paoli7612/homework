#include <iostream>

using namespace std;

int main()
{
    int r, c;

    cout << "Inserisci le dimensioni del rettangolo (1-19)x(1-19)";
    do {
        cout << endl << "righe: ";
        cin >> r;
    } while(0>=r || r>= 20);

    do {
        cout << endl << "righe: ";
        cin >> c;
    } while(0>=c || c>= 20);

    for (int y=0; y<r; y++){
        for (int x=0; x<c; x++){
            if ((x == 0) || (x == c-1))
                cout << "X";
            else if((y == 0) || (y == r-1))
                cout << "X";
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}