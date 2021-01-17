#include <iostream>
#include <fstream>

using namespace std ;

const char FILENAME[] = "gioco.txt";

struct gioco_t {
	int *carte; 
	bool *hide;		// crta i-esima true (nascosta) flase (gia rilevata)
	int N; 			// Numero di coppie nel mazzo
	
	int punteggio; 
	bool in_corso;
	
	int da_trovare; // Numero di coppie da trovare
};

void inizializza(struct gioco_t &g)
{
	g.in_corso = false;
}

bool inizia_partita(struct gioco_t &g, int N, istream &in=cin, bool is_file=false)
{
	if (g.in_corso)
		delete [] g.carte;
	
	g.da_trovare = N;
	g.N = N;
		
	N *= 2; // N coppie = N*2 carte
	g.carte = new int[N];
	g.hide = new bool[N];
	
	for (int i = 0; i < g.N*2; i++)
	{
		if (!is_file)
			cout << "Inserisci la " << i+1 << "-esima carta: ";
		in >> g.carte[i];
		g.hide[i] = true;
	}
	
	g.in_corso = true;	
	g.punteggio = 0;
}

void stampa_stato(const struct gioco_t &g, ostream &out=cout, bool is_file=false)
{
	if (!g.in_corso)
		return;
	
	if (is_file)
		out << g.da_trovare << endl; // Quante coppipe di numeri leggerai
	
	for (int i = 0; i < g.N*2; i++)
	{
		if (g.hide[i]) // Salvala solo se e' ancora da trovare
		{
			if (is_file)
				out << g.carte[i] << " ";
			else
				out << "X ";
		}
	}
		
	
	if (is_file)
		out << endl << g.punteggio;
	else
		out << "--- Punteggio: " << g.punteggio << endl;
}

/* Trasforma l'indice di tutte le carte nel indice
	delle carte ancora da svelare
	es:
		carte = 4 X X 4 X X
		indice 3 -> 5
*/
void salta_scoperte(const struct gioco_t &g, int &x)
{
	for (int pos = 0; pos < x; pos++)
		x += g.hide[pos] == false;
}

// Input indici (1, 2, 3...)
bool confronta_coppia(const struct gioco_t &g, int &x, int &y)
{
	x--;
	y--;
	
	salta_scoperte(g, x);
	salta_scoperte(g, y);
	
	if (x < 0 || y < 0 || x >= g.N*2 || y >= g.N*2){
		cerr << "Almeno un indice non e' valido" << endl;
		return false;
	}
	
	
	cout << endl << "CONTROLLO " << x << " " << y << endl;
	if (g.carte[x] == g.carte[y] && g.in_corso)
		return true;
	else
		return false;
}

bool gioca_coppia(struct gioco_t &g, int x, int y)
{
	if (!g.in_corso) // Nessuna partita in corso
		return false;
	
	if (confronta_coppia(g, x, y)) // Coppia trovata
	{
		g.punteggio += 1;
		
		// "Svela" le carte
		g.hide[x] = false;
		g.hide[y] = false;
		
		g.da_trovare--;
	}
	else 
		g.punteggio -= 1;
	
}

bool salva(const struct gioco_t &g)
{
	ofstream file(FILENAME);
	
	if (!file)
		return false;
	
	stampa_stato(g, file, true);
	
	file.close();
	return true;
}

bool carica(struct gioco_t &g)
{
	ifstream file(FILENAME);
	
	if (!file)
		return false;
	
	int N;
	file >> N;
	inizia_partita(g, N, file, true);
	
	file >> g.punteggio;
	
	file.close();
	return true;
}

int main()
{
	gioco_t g;
	inizializza(g);	
	
    const char menu[] =
		"1. Inizia partita\n"
		"2. Stampa stato\n"
		"3. Confronta coppia\n"
		"4. Salva partita\n"
		"5. Carica partita\n"
		"6. Gioca coppia\n"
		"7. Esci\n" ;
		
    while(true)
	{
		cout << menu << endl ;
		int scelta ;
		cin >> scelta ;
	
		switch(scelta)
		{
			int x, y;
			case 1: // Inizia partita
				cout << "Inserisci il numero N di coppie che sarannopresenti nel mazzo";
				cin >> x;
				inizia_partita(g, x);
			    break ;
			case 2: // Stampa stato
				stampa_stato(g);
			    break;
			    
			case 3: // Confronta coppia
				cout << "Inserisci i due indici: ";
				cin >> x >> y;
				
				if (confronta_coppia(g, x, y))
					cout << "Coppia trovata corettamente" << endl;
				else
					cout << "Coppia non trovata" << endl;
			    break;
			    
			case 4: // Salva partita
				if (!salva(g))
					cout << "Errore durante il salvataggio" << endl;
			    break;
			    
			case 5: // Carica partita
				if (!carica(g))
					cout << "Errore durante il caricamento" << endl;
			    break;
			    
			case 6: // Gioca coppia
				cout << "Inserisci i due indici: ";
				cin >> x >> y;
				
				gioca_coppia(g, x, y);
				
			    break;
			    
			case 7: // Esci
			    return 0;
			    
			default:
			    cout<<"Scelta errata"<<endl ;
		}
    }
    // non dovremmo mai arrivare qui
    return 1 ;
}
