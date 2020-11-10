#include <iostream>
#include <fstream>

#define NO_SINC -1

using namespace std;

enum Stato{fallito, funzionante};
const char filename[] = "data.txt";
typedef unsigned int pid;

struct Processo {
    pid p = 0;
    Stato stato = funzionante;
    int sinc = NO_SINC;
};

struct Sistema {
    Processo* processi;
    int N;
    bool init = false;
} sistema;

Processo* cerca(pid p){
    for (int i=0; i<sistema.N; i++)
        if (p == sistema.processi[i].p)
            return &sistema.processi[i];
    return &sistema.processi[0];
}

pid chiedi_pid(int n=-1){
    pid a;
    do {
        cout << "Inserisci il pid (intero tra 0 e " << sistema.N;
        if (n != -1)
            cout << ", non " << n;
        cout << "): ";
        cin >> a;
    } while (a<0 || a>=sistema.N || a == n);
    return a;
}

void inizializza(int n){
    sistema.N = n;
    sistema.processi = new Processo[n];
    for (int i=0; i<n; i++)
        sistema.processi[i].p = i;
    sistema.init = true;
}

void stampa_insieme(){
    for (int i=0; i<sistema.N; i++){
        Processo* p = &sistema.processi[i];
        
        cout << p->p << "\t";
        if (p->stato == funzionante)
            cout << "funzionante"; 
        else
            cout << "fallito ";
        cout << "\t";
        if (p->sinc == NO_SINC)
            cout << "no-sinc";
        else
            cout << p->sinc;

        cout << endl;
    }
}

void salva_insieme(){
    ofstream file(filename);
    file << sistema.N << endl;

    for (int i=0; i<sistema.N; i++){
        Processo* p = &sistema.processi[i];
        file << p->p << " " << p->stato << " " << p->sinc << endl;
    }

    file.close();
}

void carica_insieme(){
}

void crea_sincronizzazione(int p1, int p2){
    Processo* a = cerca(p1);
    Processo* b = cerca(p2);

    if (b->stato != fallito && a->sinc == NO_SINC)
        a->sinc = b->p;
}

void imposta_fallito(int p){
    Processo* a = cerca(p);
    a->stato = fallito;
}

int main(int argc, char** argv){
    const char menu[] =
        "1. Inizializza\n"
        "2. Stampa\n"
        "3. Salva\n"
        "4. Carica\n"
        "5. Sincronizza\n"
        "6. Imposta fallito\n"
        "7. Esci\n";
    bool running = true;
    while (running){
        int scelta;
        cout << menu;
        
        cin >> scelta;

        switch (scelta)
        {
        case 1: // inizializza
            /*if (sistema.init){
                char s;
                cout << "I dati inseriti fin ora andranno sovrascritti. Continuare? (S/n): ";
                cin >> s;
                if (s != 'S' && s != 's')
                    break;                    
            }*/
            int n;
            cout << "Inserisci il numero di processi: ";
            cin >> n;
            inizializza(n);
            cout << "Sistema inizializzato con " << n << " processi" << endl;
            break;
        case 2: // stampa
            stampa_insieme();
            break;
        case 3: // salva
            salva_insieme();
            break;
        case 4: // carica
            carica_insieme();
            break;
        case 5: // sincronizza
            pid a, b;
            cout << "Processo da sincronizzare" << endl;
            a = chiedi_pid();
            cout << "Processo con cui sincronizzare" << endl;
            b = chiedi_pid(a);
            crea_sincronizzazione(a, b);

            break;
        case 6: // imposta fallito
            break;
        case 7: // esci
            break;
        default:
            cout << "\t_ scelta non valida _" << endl;;
            break;
        }
    }



    return 0;
}