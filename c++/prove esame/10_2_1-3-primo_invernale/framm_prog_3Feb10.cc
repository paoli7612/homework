#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 3;
const int M = 5;
const int L = 10; 

const char FILENAME[] = "partita.txt";

enum direzione {VERTICALE, ORIZZONTALE, DIAGONALE};
struct pos_t { int x, y; };

struct partita_t {
	char mat[SIZE][SIZE];
	int n_parole;
	char parole[M][L];
};

void inizializza(struct partita_t &p){
	for (int y=0; y<SIZE; y++)
		for (int x=0; x<SIZE; x++)
			p.mat[y][x] = 'a';
	p.n_parole = 0;
}

void stampa(struct partita_t &p, ostream &os, bool isFile){
	for (int y=0; y<SIZE; y++){
		for (int x=0; x<SIZE; x++)
			os << p.mat[y][x] << " ";
		os << endl;
	}
	if (isFile)
		os << p.n_parole << " ";
	for (int i=0; i<p.n_parole; i++){
		os << p.parole[i] << " ";
	}
}

void carica(struct partita_t &p, istream &is, bool isFile){
	// MATRICE
	if (!isFile)
		cout << "Inserisci le " << SIZE*SIZE << " caselle della matrice: ";
	for (int y=0; y<SIZE; y++)
		for (int x=0; x<SIZE; x++)
			is >> p.mat[y][x];
	
	// N_PAROLE
	if (!isFile)
		cout << "numero parole da cercare: ";
	is >> p.n_parole;
	
	// PAROLE
	for (int i=0; i<p.n_parole; i++){
		if (!isFile)
			cout << "Inserisci la parola numero " << i+1 << ": ";
		is >> p.parole[i];
	}
}

void nuova_partita(struct partita_t &p){
	carica(p, cin, false);
}

void stampa_partita(struct partita_t &p){
	stampa(p, cout, false);
}

void salva_partita(struct partita_t &p){
	ofstream file(FILENAME);
	stampa(p, file, true);
	file.close();
}

void carica_partita(struct partita_t &p){
	ifstream file(FILENAME);
	carica(p, file, true);
	file.close();
}

// Vero se le parole sono uguali
bool equals(char* p1, char* p2){
	int i;
	for (i=0; p1[i]; i++)
		if (p1[i] != p2[i])
			return false;
	return p1[i] == p2[i]; // cosi siamo sicuri che p2 non sia piu lunga
}

// Indice della parola se parola è una parola della partita p da trovare (-1 altrimenti)
bool parola_in(struct partita_t &p, char* parola){
	for (int i=0; i<p.n_parole; i++)
		if (equals(parola, p.parole[i]))
			return i;
	return -1;
}

// Copia la parola 'copia' e la incolla nella parola 'incolla'
void copia_incolla(char incolla[M], char copia[M]){
	int i;
	for (i=0; copia[i]; i++)
		incolla[i] = copia[i];
	incolla[i] = '\0'; // terminatore per sicurezza
}

// Rimuove la parola di indice i dalle parole da cercare
void rimuovi_parola(struct partita_t &p, int i){
	p.n_parole--;
	for (int a=i; a<p.n_parole; a++)
		copia_incolla(p.parole[a], p.parole[a+1]);
}

bool confronta_parola(struct partita_t &p, char* parola, pos_t pos, direzione dir){
	
	int i = parola_in(p, parola);
	
	// La parola non è da cercare
	if (i == -1)
		return false;
		
	
	for (int i=0; parola[i]; i++){
		switch(dir){
			case VERTICALE:
				if (parola[i] != p.mat[pos.y+i][pos.x])
					return false;
				break;
			case ORIZZONTALE:
				if (parola[i] != p.mat[pos.y][pos.x+i])
					return false;
				break;
			case DIAGONALE:
				if (parola[i] != p.mat[pos.y+i][pos.x+i])
					return false;
				break;
		}
	}
	
	// Passiamo l'indice della parola da eliminare, che ci siamo calcolati prima
	rimuovi_parola(p, i);
		
	return true;
}

void trova_parola(struct partita_t &p, char* par, pos_t pos, direzione dir){
	confronta_parola(p, par, pos, dir);
	
	if (p.n_parole == 0)
		cout << "Comunico la avvenuta vittoria" << endl;
}

void elenca_pos_parola(struct partita_t &p, char* par, direzione dir){
	for (int i=0; par[i]; i++){
		switch(dir){
			case VERTICALE:
				if (par[i] != p.mat[pos.y+i][pos.x])
					return false;
				break;
			case ORIZZONTALE:
				if (par[i] != p.mat[pos.y][pos.x+i])
					return false;
				break;
			case DIAGONALE:
				if (par[i] != p.mat[pos.y+i][pos.x+i])
					return false;
				break;
		}
	}
}

int main(){
	partita_t p;
	inizializza(p);
	carica_partita(p);
	stampa_partita(p);
	//salva_partita(p);
	trova_parola(p, "tom", {1, 0}, VERTICALE);
	stampa_partita(p);
	trova_parola(p, "aaa", {0, 0}, VERTICALE);
	stampa_partita(p);
	trova_parola(p, "aoa", {0, 0}, DIAGONALE);
	stampa_partita(p);
	
    const char menu[] =
		"\t1 Nuova partita\n"
		"\t2 Stampa partita\n"
		"\t3 Salva partita\n"
		"\t4 Carica partita\n"
		"\t5 Confronta parola\n"
		"\t6 Trova parola\n"
		"\t7 Elenca posizioni parola\n"
		"\t8 Uscita\n";

    while(true) {
		cout<<endl<<menu<<endl ;
		int scelta ;
		cin>>scelta ;
		switch(scelta) {
			case 1:
			    break ;
			case 2:
			    break ;
			case 3:
			    break ;
			case 4:
			    break ;
			case 5:
			    break ;
			case 6:
			    break ;
			case 7:
			    break ;
			case 8:
			    return 0 ;
		}
	}

    // non si dovrebbe mai arrivare qui
    return 1 ;
}

