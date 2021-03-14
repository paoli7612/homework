#include <ctime>
#include <stdlib.h>
#include <iostream>

using namespace std ;

/*
    Timer 3 secondi
*/

int main()
{
    const int MAX = 3;
    int t = time(0);
    while(time(0) - t < MAX) {
        cout << "\r" << time(0)-t+1 << flush;
        system("sleep 1");
    }
    return 0 ;
}

