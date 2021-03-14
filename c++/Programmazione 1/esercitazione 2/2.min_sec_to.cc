#include <iostream>

using namespace std;

int main(int argc, char** argv){

    int min, sec;

    cout << "Inserisci il numero dei minuti: ";
    cin >> min;

    cout << "Inserisci il numero dei secondi: ";
    cin >> sec;

    int t = min*60 + sec;

    cout << min << ":" << sec << "  ->  " << t << endl;
    

    return 0;
}