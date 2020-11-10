#include <iostream>

#define NO_SINC -1

using namespace std;

enum Stato{funzionante, fallito};

struct Processo {
    int pid = 0;
    Stato stato = funzionante;
    int sinc = NO_SINC;
};

struct Sistema {
    Processo* processi;
    int N;
};

void stampa_insieme(Sistema sistema){
    for (int i=0; i<sistema.N; i++){
        Processo* p = &sistema.processi[i];
        
        cout << p->pid << "\t";
        if (p->stato == funzionante)
            cout << "funzionante"; 
        else
            cout << "funzionante";
        cout << "\t";
        if (p->sinc == NO_SINC)
            cout << "no-sinc";
        else
            cout << p->sinc;
            
        cout << endl;
    }
}

void inizializza(Sistema &sistema, int n){
    sistema.N = n;
    sistema.processi = new Processo[n];
    for (int i=0; i<n; i++)
        sistema.processi[i].pid = i;
}

int main(int argc, char** argv){
    Sistema s;
    inizializza(s, 4);
    stampa_insieme(s);

    return 0;
}