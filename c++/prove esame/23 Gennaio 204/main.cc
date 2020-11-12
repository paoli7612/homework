#include <iostream>
#include <cstring>

using namespace std;

const int N = 10;
const int M = 30;

typedef char* Codice;

bool equals(Codice a, Codice b){
    if (strlen(a) != strlen(b))
        return false;
    for (int i=0; i<strlen(a); i++)
        if (a[i] != b[i])
            return false;
    return true;
}

int ask(const char text[]){
    cout << text << ": ";
    int a;
    cin >> a;
    return a;
}

char* ask_codice(){
    cout << "Codice: ";
    Codice codice = new char[M];
    cin >> codice;
    codice[strlen(codice)] = '-';
    return codice;
}

struct Pos {
    int scaffale;
    int ripiano;
};

struct Prodotto {
    Pos posizione;
    Codice codice;
};

struct Magazzino {
    Prodotto prodotti[N];
    int T = 0;
} magazzino;

/* Legge da stdin, e ritorna, il codice di un prodotto e la posizione in cui
va collocato tale prodotto nel magazzino (questa funzionalità si limita a leggere e ritornare tali
informazioni, e non inserisce il prodotto nel magazzino, operazione di cui si occupa invece la
prossima funzionalità). Il codice del prodotto ritornato deve essere memorizzato in array di
caratteri delle dimensioni minime necessarie per contenere tale codice. La funzione deve
occuparsi di controllare anche che l'utente non inserisca un codice più lungo di M caratteri. Nel
caso in cui l'utente inserisca più di M caratteri, può tornare utile la funzione di svuotamento
dello stdin di tutti i caratteri successivi fino al newline (fornita col frammento di codice), per
eliminare i caratteri in eccesso ed evitare condizioni di errore. */
void leggi_codice_posizione(){

}

/*Inserisce il prodotto di codice cod nella posizione pos nel
magazzino*/
void inserisci_prodotto(Codice codice, Pos pos){
    int n = magazzino.T++;
    magazzino.prodotti[n].codice = codice;
    magazzino.prodotti[n].posizione = pos;
}

/* Stampa codice e posizione di tutti i prodotti contenuti nel magazzino. Si
ottiene il punteggio massimo se si riesce a stampare le informazioni col seguente formato
(notare l'allineamento della seconda colonna)
dga27- 56,12
y2r6sw- 1,78 */
void stampa_posizione(Pos p){
    cout << "(" << p.ripiano << "," << p.scaffale << ")";
}
void stampa_prodotto(Prodotto p){
    cout << p.codice << " ";
    stampa_posizione(p.posizione);
    cout << endl;
}
void stampa_prodotti(){
    for (int i=0; i<magazzino.T; i++)
        stampa_prodotto(magazzino.prodotti[i]);
}

/* Elimina tutti i prodotti di codice cod */
void elimina_codice_prodotto(Codice codice){
    for (int i=0; i<magazzino.T; i++){
        Prodotto* p = &magazzino.prodotti[i];
        if (equals(p->codice, codice)){
            // Elimina prodotto
            cout << "Elimina prodotto" << endl;
        }
    }

}
/* Salva il contenuto del magazzino in un file di testo */
void salva_prodotti(){

}

/* Carica il contenuto del magazzino dal file. Il precedente contenuto è perso */
void carica_prodotti(){

}


int main(int argc, char** argv){
    const char menu[] = 
        "1. Leggi codice promozione\n"
        "2. Inserisci prodotto\n"
        "3. Stampa prodotti\n"
        "4. Salva prodotti\n"
        "5. Carica prodotti\n"
        "6. Elimina codice prodotto\n"
        "7. Esci\n";

    bool running = true;
    while (running){

        cout << menu;

        int scelta;
        cin >> scelta;

        Codice codice;
        Pos posizione;

        switch (scelta){
            case 1: // Leggi codice posizione
                codice = ask_codice();
                posizione.scaffale = ask("Scaffale");
                posizione.ripiano = ask("Ripiano");
                inserisci_prodotto(codice, posizione);
                break;
            case 2: // Inserisci prodotto       
                break;
            case 3: // Stampa prodotti
                stampa_prodotti();
                break;
            case 4: // Salva prodotti
                break;
            case 5: // Carica prodotti
                break;
            case 6: // Elimina codice prodotto
                codice = ask_codice();
                elimina_codice_prodotto(codice); 
                break;
            case 7: // Esci
                running = false;
                break;
        }

    }

    return 0;
}