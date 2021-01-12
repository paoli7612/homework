#include <iostream>
#include <fstream>

using namespace std;

const int Y = 5; // Numero righe
const int X = 10; // Numero colonne

const char FILENAME[] = "spiaggia.dat";


enum stato{LIBERO, OCCUPATO};

struct spiaggia_t {
	stato omb[Y][X]; // Ombrelloni
};


// Inizializza spiaggia tutti liberi
void inizializza(struct spiaggia_t &s){
	for (int y=0; y<Y; y++)
		for (int x=0; x<X; x++)
			s.omb[y][x] = LIBERO;
}


// Ritorna la colonna dell'obrellone o -1
int noleggia_ombrellone(struct spiaggia_t &s, int fila){
	for (int i=0; i<X; i++)
		if (s.omb[fila][i] == LIBERO){
			s.omb[fila][i] = OCCUPATO;
			return i;
		}
	
	// non ce ne sono liberi su quella fila
	return -1;
}


bool is_isolato(const struct spiaggia_t &s, int x, int y){
	// True se il la (x, y) è libero (se x o y fuori dalla spiaggia -> true)
	bool get(int x, int y){
		if (x<0 || y<0 || x>=X || y>=Y)
			return true;
		else
			return s.omb[y][x] == LIBERO	
	}
	return get(x-1, y) && get(x+1, y) && get(x, y-1) && get(x, y+1);
}

// occupa e ritorna il numero della fila dell'ombrellone primo ombrellone isolato disponibile altrimenti da -1
int noleggia_ombrellone_isolato(struct spiaggia_t &s){
	for (int y=0; y<Y; y++){
		for (int x=0; x<X; x++)
			if (is_isolato(s, x, y)){
				s.omb[y][x] = OCCUPATO;
				return y;
			}
	// non ne ho trovati
	return -1;
}

void stampa_stato(const struct spiaggia_t &s){
	for (int y=0; y<Y; y++){
		for (int x=0; x<X; x++)
			if (s.omb[y][x] == OCCUPATO)
				cout << "O ";
			else
				cout << "L ";
		cout << endl;
	}
}

void salva(const struct spiaggia_t &s){
	ofstream file(FILENAME);
	file.write((char*)&s, sizeof(spiaggia_t));
	file.close();
}

void carica(struct spiaggia_t &s){
	ifstream file(FILENAME);
	file.read((char*)&s, sizeof(spiaggia_t));
	file.close();
}

int main()
{
	
	spiaggia_t s;
	inizializza(s);
	carica(s);
	stampa_stato(s);
	noleggia_ombrellon(s, 3);
	salva(s);
	return 0;
	
	
    const char menu[]=
		"1. Noleggia ombrellone\n"
		"2. Stampa stato\n"
		"3. Salva stato\n"
		"4. Carica stato\n"
		"5. Noleggia ombrellone isolato\n"
		"6. Noleggia ombrelloni vicini\n"
		"7. Esci\n";

    while(true) {
		cout<<menu<<endl ;
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
			    return 0 ;
			default:
			    cout<<"Scelta errata"<<endl ;
		}
    }
    // non dovremmo mai arrivare qui
    return 1 ;
}
