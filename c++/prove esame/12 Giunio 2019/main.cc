#include <iostream>
#include <fstream>

#define NO_SINC -1

using namespace std;

enum Stato{fallito, funzionante};
const char filename[] = "data.txt";


struct Processo {
    int pid = 0;
    Stato stato = funzionante;
    int sinc = NO_SINC;
};

struct Sistema {
    Processo* processi;
    int N;
} sistema;

Processo* cerca(int pid){
    for (int i=0; i<sistema.N; i++)
        if (pid == sistema.processi[i].pid)
            return &sistema.processi[i];
    return &sistema.processi[0];
}

void stampa_insieme(){
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

void inizializza(int n){
    sistema.N = n;
    sistema.processi = new Processo[n];
    for (int i=0; i<n; i++)
        sistema.processi[i].pid = i;
}

void salva_insieme(){
    ofstream file(filename);
    file << sistema.N << endl;

    for (int i=0; i<sistema.N; i++){
        Processo* p = &sistema.processi[i];
        file << p->pid << " " << p->stato << " " << p->sinc << endl;
    }

    file.close();
}

void crea_sincronizzazione(int p1, int p2){
    Processo* a = cerca(p1);
    Processo* b = cerca(p2);
    a->sinc = b->pid;
}

int main(int argc, char** argv){
    Sistema sistema;
    inizializza(4);
    crea_sincronizzazione(2, 1);
    stampa_insieme();
    salva_insieme();
    return 0;
}