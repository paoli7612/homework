#include <iostream>
#include <fstream>

using namespace std;

const int W = 3, H = 3; // Width, Height crucipuzzle
const int M = 10; // Numero massimo di parole da trovare

enum direzione {VERTICALE, ORIZZONTALE, DIAGONALE};
struct pos_t {
	int x, y;
};

struct crucipuzzle_t {
	char mat[H][W];
	char **parole;
	int n_parole;
};

void initializza(struct crucipuzzle_t &c){
	c.n_parole = 0;
	for (int x=0; x<W; x++)
		for (int y=0; y<H; y++)
			c.mat[y][x] = 'a';
	// Prima di fare nuova partita o caricare dal file faremmo il delete
	c.parole = new char*[0];
}

void nuova_partita(struct crucipuzzle_t &c){
	
	delete [] c.parole;
	
	//Legge da stdin il contenuto della matrice
	cout << "Inserisci il contenuto della matrice: ";
	for (int x=0; x<W; x++)
		for (int y=0; y<H; y++)
			cin >> c.mat[y][x];
	
	//Numero parole
	cout << "Inserisci il numero delle parole da trovare: ";
	cin >> c.n_parole;
	c.parole = new char*[c.n_parole];
	
	for (int i=0; i<c.n_parole; i++){
		cout << "Inserisci la parola da trovare numero " << i+1 << ": ";
		c.parole[i] = new char[M];
		cin >> c.parole[i];
	}
}

// Stampa matrice e parole da trovare
void stampa_partita(const struct crucipuzzle_t &c, ostream &os){
	for (int x=0; x<W; x++){
		for (int y=0; y<H; y++)
			os << c.mat[y][x] << " ";
		cout << endl;
	}
	for (int i=0; i<c.n_parole; i++)
		os << c.parole[i] << " ";
}

// Salva partita sul file data.txt
void salva_partita(const struct crucipuzzle_t &c){
	ofstream file("data.txt");
	file << c.n_parole << " ";
	stampa_partita(c, file);
	file.close();
}

// Carica partita dal file data.txt
void carica_partita(struct crucipuzzle_t &c){
	ifstream file("data.txt");
	
	file >> c.n_parole;
	for (int x=0; x<W; x++)
		for (int y=0; y<H; y++)
			file >> c.mat[y][x];
	
	delete[] c.parole;
	c.parole = new char*[c.n_parole];
	
	for (int i=0; i<c.n_parole; i++){
		c.parole[i] = new char[M];
		file >> c.parole[i];	
	}
		
	
	file.close();	
}

// Vero se le tue parole sono uguali
bool equals(const char* p1, const char* p2){
	for (int i=0; p1[i] != '\0'; i++)
		if (p1[i] != p2[i])
			return false;
	return true;
}

// Vero se la parola è ancora da trovare
bool pdt(const struct crucipuzzle_t &c, char* par){
	for (int i=0; i<c.n_parole; i++){
		if (equals(c.parole[i], par))
			return true;
	}
	return false;
}

/*Se la parola par è una di quelle da trovare, si controlla se è
presente nella matrice a partire dalla posizione pos e lungo la direzione dir, e se le cose stanno
così si elimina tale parola dall'elenco delle parole da trovare e, se non ci sono più parole da
trovare comunica l'avvenuta vittoria.*/
bool trova_parola(struct crucipuzzle_t &c, char* par, pos_t pos, direzione dir){
	if (!pdt(c, par))
		return false;
	
	cout << "mat" << endl;
	for (int i=0; par[i] != '\0'; i++) {
		switch(dir){
			case VERTICALE:
				if (par[i] != c.mat[pos.x][pos.y+1])
					return false;
				break;		
		}
	}
	
	return true;
	
}

int main(){
	crucipuzzle_t c;
	initializza(c);
	
    const char menu[] =
		"\t1 Nuova partita\n"
		"\t2 Stampa partita\n"
		"\t3 Salva partita\n"
		"\t4 Carica partita\n"
		"\t5 Confronta parola\n"
		"\t6 Trova parola\n"
		"\t7 Elenca posizioni parola\n"
		"\t8 Uscita\n";


	cout << VERTICALE << endl;

	bool run = true;
    while(run) {
		cout<<endl<<menu<<endl ;
		int scelta ;
		cin>>scelta ;
		switch(scelta) {
			char* par;
			int n;
			pos_t pos;
			direzione dir;
			case 1: // Nuova partita
				nuova_partita(c);
			    break ;
			case 2: // Stampa partita
				stampa_partita(c, cout);
			    break ;
			case 3: // Salva partita
				salva_partita(c);
			    break ;
			case 4: // Carica partita
				carica_partita(c);
			    break ;
			case 5: // Confronta parola
				cout << "Inserisci la parola: ";
				par = new char[M];
				cin >> par;
				cout << "x posizione: "; cin >> pos.x;
				cout << "y posizione: "; cin >> pos.y;
				cout << "Direzione (0 Verticale, 1 Orizzontale, 2 Obliquo)";
				cin >> n;
				if (trova_parola(c, par, pos, (direzione)n))
					cout << "Parola trovata" << endl;
				else cout << "Parola non trovata" << endl;
			    break ;
			case 6:
			    break ;
			case 7:
			    break ;
			case 8:
			    run = false;
			    break;
			default:
				cout << "Scelta errata" << endl;
		}
    }

    return 0;
}
