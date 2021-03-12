#include <iostream>

using namespace std;

/*
    Chiedi due numeri interi e stampa 1 se il primo 
    è divisibile per il secondo, altrimenti stampa 0
*/


int main(int argc, char** argv){

    int a, b;
    
    cout << "Inserisci i due numeri: ";
    cin >> a >> b;

    cout << ((a/b)*b)-a+1 << endl;

    return 0;
}

/*    Chiedi due numeri interi e stampa 1 se il primo 

#include <iostream>

using namespace std;

    è divisibile per il secondo, altrimenti stampa 0


int main(int argc, char** argv){

    int a, b;
    
    cout << "Inserisci i due numeri: ";
    cin >> a >> b;
    int m = a%b;
    cout << (m+2)%(m+1) << enld

    return 0;
}

*/
