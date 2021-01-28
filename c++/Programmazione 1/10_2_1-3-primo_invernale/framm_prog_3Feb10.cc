#include <iostream>
#include <fstream>

using namespace std;

const int GRANDEZZA_MATRICE = 3; // 3 x 3
const int MASSIMO_PAROLE = 5;
const char FILENAME[] = "crucipuzzle.txt";

struct pos_t {int x, y; };
enum dir_t {VERTICALE, ORIZZONTALE, OBLIQUO};

struct crucipuzzle_t {
	char mat[GRANDEZZA_MATRICE][GRANDEZZA_MATRICE];
	int n_parole;
	char parole[MASSIMO_PAROLE][GRANDEZZA_MATRICE+1];
};

void inizializza_vuoto(crucipuzzle_t &crucipuzzle) {
	crucipuzzle.n_parole = 0;
}

bool nuova_partita(crucipuzzle_t &crucipuzzle, istream &is, bool is_file)
{
	if (!is_file)
		cout << "Inserisci la matrice " << GRANDEZZA_MATRICE << "x" << GRANDEZZA_MATRICE << endl;
	for (int y=0; y<GRANDEZZA_MATRICE; y++)
		for (int x=0; x<GRANDEZZA_MATRICE; x++)
			is >> crucipuzzle.mat[y][x];

	if (!is_file)
		cout << "Quante parole: ";
	int n;
	is >> n;
	for (int i=0; i<n; i++)
		is >> crucipuzzle.parole[crucipuzzle.n_parole++];
	return true;
}

void stampa_partita(const crucipuzzle_t &crucipuzzle, ostream &os/*=cout*/, bool is_file/*=false*/)
{
	if (crucipuzzle.n_parole == 0)
		return;

	for (int y=0; y<GRANDEZZA_MATRICE; y++){
		for (int x=0; x<GRANDEZZA_MATRICE; x++)
			os << crucipuzzle.mat[y][x] << " ";
		os << endl;
	}
	if (is_file)
		os << crucipuzzle.n_parole << endl;
	for (int i=0; i<crucipuzzle.n_parole; i++)
		os << crucipuzzle.parole[i] << endl;
}

bool salva(const crucipuzzle_t &crucipuzzle)
{
	ofstream file(FILENAME);

	if (!file)
		return false;

	stampa_partita(crucipuzzle, file, true);
	
	// file.close();
	return (bool)file;
}

bool carica(crucipuzzle_t &crucipuzzle)
{
	ifstream file(FILENAME);

	if (!file)
		return false;

	nuova_partita(crucipuzzle, file, true);
	
	// file.close();
	return (bool)file;
}

bool confronta_parola(crucipuzzle_t &crucipuzzle, char par[GRANDEZZA_MATRICE], pos_t pos, dir_t dir)
{
	for (int i=0; i<GRANDEZZA_MATRICE; i++)
		switch (dir)
		{
		case VERTICALE:
			if (crucipuzzle.mat[pos.y+i][pos.x] != par[i])
				return false;
			break;
		case ORIZZONTALE:
			if (crucipuzzle.mat[pos.y][pos.x+1] != par[i])
				return false;
		case OBLIQUO:
			if (crucipuzzle.mat[pos.y+i][pos.y+i] != par[i])
				return false;
		default:
			break;
		}
	return true;
}

// Ritorna vero se la stringa a == stringa b
bool equals(const char a[GRANDEZZA_MATRICE], const char b[GRANDEZZA_MATRICE])
{
	int i;
	for (i=0; a[i]!='\0'; i++)
		if (a[i] != b[i])
			return false;
	return a[i] == b[i];
}

void str_copy(char a[GRANDEZZA_MATRICE], const char b[GRANDEZZA_MATRICE])
{
	int i;
	for (i=0; b[i]!='\0'; i++)
		a[i] = b[i];
	a[i] = b[i];
}

bool trova_parola(crucipuzzle_t &crucipuzzle, char par[GRANDEZZA_MATRICE], pos_t pos, dir_t dir)
{	
	bool trovata = false;
	for (int i=0; i<crucipuzzle.n_parole; i++)
	{
		if (trovata)
			str_copy(crucipuzzle.parole[i], crucipuzzle.parole[i+1]);
		else if (equals(crucipuzzle.parole[i], par))
			trovata = confronta_parola(crucipuzzle, par, pos, dir);
	}

	if (trovata)
	{
		crucipuzzle.n_parole--;
		if (crucipuzzle.n_parole == 0)
			{
				cout << "Hai vinto";
				exit(0);
			}
		return true;
	}

	return false;
}

void chiedi(char par[GRANDEZZA_MATRICE], pos_t &pos, dir_t &dir)
{
	int i;
	cout << "Inserisci parola: ";
	cin >> par;
	cout << "Inserisci coordinate partenze(x, y): ";
	cin >> pos.x >> pos.y;
	cout << "Inserisci direzione parola(1 Orizzontale, 2 Verticale, 3 Obliqua): ";
	cin >> i;
	dir = (dir_t)(i-1);
}

int main()
{
	crucipuzzle_t crucipuzzle;
	inizializza_vuoto(crucipuzzle);

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
	case 1: // Nuova partita
		nuova_partita(crucipuzzle, cin, false);
	    break ;
	case 2: // Stampa partita
		stampa_partita(crucipuzzle, cout, false);
	    break ;
	case 3: // Salva partita
		if (!salva(crucipuzzle))
			cerr << "Salvataggio fallito" << endl;
	    break ;
	case 4: // Carica partita
		if (!carica(crucipuzzle))
			cerr << "Caricamento fallito" << endl;
	    break ;
	case 5: // Confronta parola
	{
		char par[GRANDEZZA_MATRICE];
		pos_t pos;
		dir_t dir;
		chiedi(par, pos, dir);

		if (confronta_parola(crucipuzzle, par, pos, dir))
			cout << "Parola trovata" << endl;
		else
			cout << "Parola non trovata" << endl; 
	}
	    break ;
	case 6: // Trova parola
	{
		char par[GRANDEZZA_MATRICE];
		pos_t pos;
		dir_t dir;
		chiedi(par, pos, dir);

		if (confronta_parola(crucipuzzle, par, pos, dir))
			cout << "Parola trovata" << endl;
		else
			cout << "Parola non trovata" << endl;
	}
	    break ;
	case 7: // Elenca posizioni parola
	    break ;
	case 8: // Uscita
	    return 0 ;
	}
    }

    // non si dovrebbe mai arrivare qui
    return 1 ;
}
