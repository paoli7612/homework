#include <iostream>
#include <ctime>
using namespace std;

/*
    Scrivere un programma che stampa ogni secondo
*/

int main()
{
    while (1){
        cout << time(NULL) << endl;
        system("sleep 1")
    }
    return 0;
}