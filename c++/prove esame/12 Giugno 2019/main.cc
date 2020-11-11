#include <iostream>
#include <fstream>

#define NO_SINC -1

using namespace std;

const char filename[] = "data.txt";
typedef int Pid;

struct Processo {
    Pid pid = 0;
    bool stato = true;
    Pid sinc = NO_SINC;
};

struct Sistema {
    Processo* processi;
    int N;
    bool init = false;
} sistema;

Processo* cerca(Pid p){
    for (int i=0; i<sistema.N; i++)
        if (p == sistema.processi[i].pid)
            return &sistema.processi[i];
    return &sistema.processi[0];
}

Pid chiedi_pid(int n=-1){
    Pid pid;
    do {
        cout << "Inserisci il pid (intero tra 0 e " << sistema.N-1;
        if (n != -1)
            cout << ", non " << n;
        cout << "): ";
        cin >> pid;
    } while (pid<0 || pid>=sistema.N || pid == n);
    return pid;
}

void inizializza(int n){
    sistema.N = n;
    sistema.processi = new Processo[n];
    for (int i=0; i<n; i++)
        sistema.processi[i].pid = i;
    sistema.init = true;
}

void stampa_insieme(){
    for (int i=0; i<sistema.N; i++){
        Processo* p = &sistema.processi[i];
        
        cout << p->pid << "\t";
        if (p->stato)
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
        file << p->pid << " " << p->stato << " " << p->sinc << endl;
    }

    file.close();
}

void carica_insieme(){
    ifstream file(filename);
    int n;
    file >> n;
    inizializza(n);

    for (int i=0; i<n; i++){
        Pid pid, sinc;
        bool stato;
        file >> pid >> stato >> sinc;
        Processo *p = &sistema.processi[i];
        p->stato = stato;
        p->sinc = sinc;
    }

    file.close();
}

void crea_sincronizzazione(Pid p1, Pid p2){
    Processo* a = cerca(p1);
    Processo* b = cerca(p2);

    if (b->stato && a->sinc == NO_SINC)
        a->sinc = b->pid;
    else{
        cout << "Impossibile completare l'operazione" << endl;
    }
}

void imposta_fallito(int p){
    Processo* a = cerca(p);
    a->stato = false;
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

        if (scelta > 1 && scelta < 7 && !sistema.init && scelta != 4){
            cout << "Insieme non inizializato" << endl;
            continue;
        }

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
            Pid a, b;
            cout << "Processo da sincronizzare" << endl;
            a = chiedi_pid();
            cout << "Processo con cui sincronizzare" << endl;
            b = chiedi_pid(a);
            crea_sincronizzazione(a, b);
            break;
        case 6: // imposta fallito
            Pid c;
            cout << "Processo da rendere \"fallito\"" << endl;
            c = chiedi_pid();
            imposta_fallito(c);
            break;
        case 7: // esci
            running = false;
            break;
        default:
            cout << "\t_ scelta non valida _" << endl;;
            break;
        }
    }



    return 0;
}