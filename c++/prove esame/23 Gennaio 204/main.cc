#include <iostream>

using namespace std;

const int N = 10;
const int M = 5;

typedef char* Codice;

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

/* Elimina tutti i prodotti di codice cod. Si ottiene il punteggio
massimo se si realizza questa funzionalità a costo O(N) (anche se questo comporta la creazione
di oggetti temporanei e la loro successiva eliminazione). */
void elimina_codice_prodotto(Codice codice){

}


int main(int argc, char** argv){
    Codice codice = new char[M];
    Pos pos;
    pos.ripiano = 1;
    pos.scaffale = 2;
    codice = "asd";
    inserisci_prodotto(codice, pos);
    stampa_prodotti();


    bool running = true;
    while (running){

        int scelta;
        cin >> scelta;

        switch (scelta){
            case 1: // Leggi codice posizione
                Codice codice = new char[M];
                cout << "Codice: ";
                cin >> codice;
                break;
            case 2: // Inserisci prodotto       
                break;
            case 3: // Stampa prodotti
                break;
            case 6: // Elimina codice prodotto
                break;
            case 7: // Esci
                running = false;
                break;
        }

    }

    return 0;
}