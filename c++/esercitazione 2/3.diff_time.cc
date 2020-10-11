#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv){

    int m1, s1, m2, s2;

    cout << "\tT1" << endl;
    cout << "Minuti: ";
    cin >> m1;
    cout << "Secondi: ";
    cin >> s1;


    cout << "\tT2" << endl;
    cout << "Minuti: ";
    cin >> m2;
    cout << "Secondi: ";
    cin >> s2;

    int t1 = m1*60 + s1;
    int t2 = m2*60 + s2;

    cout << abs(t1-t2) << endl;

    return 0;
}