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

    int t3 = abs(t1-t2);

    int min = t3/60;
    int sec = t3%60;

    cout << "T1 = " << m1 << ":" << s1 << endl;
    cout << "T2 = " << m2 << ":" << s2 << endl;
    cout << "differenza tra T1 e T1 = " << min << ":" << sec << endl;

    return 0;
}