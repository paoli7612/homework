#include <iostream>
#include <fstream>

using namespace std;

const int MAXLUN = 30;
const char FILENAME[] = "testo.txt";

// legge una riga da istream is e la copia nel buffer riga
void leggi_riga(istream &is, char *riga)
{
 // consuma eventuali sequenze di newline,
 // per evitare errori nella lettura di
 // una riga che si sta per effettuare
	while (is.peek() == '\n')
			is.get() ;

	is.get(riga, MAXLUN) ; // legge una riga
	is.get() ; // consuma il newline che
		   // segue la riga appena letta
}


struct testo_t {
	char (*righe)[MAXLUN];
	int n_righe;
};

void inizializza(testo_t &testo)
{
	testo.n_righe = -1;
}

bool inizializza_testo(testo_t &testo, const int n_righe, istream &is)
{
	if (n_righe < 0)
		return false;

	if (testo.n_righe != -1 && testo.n_righe != n_righe)
		delete [] testo.righe;

	testo.righe = new char[n_righe][MAXLUN];
	testo.n_righe = n_righe;

	for (int i=0; i<n_righe; i++)
	{
		leggi_riga(is, testo.righe[i]);
	}

	return true;
}

void stampa_testo(const testo_t &testo, ostream &os, const bool is_file)
{
	if (is_file)
		os << testo.n_righe << endl;

	for (int i=0; i<testo.n_righe; i++)
		os << testo.righe[i] << endl;
}

bool salva_testo(const testo_t &testo)
{
	ofstream file(FILENAME);

	if (!static_cast<bool>(file))
		return false;

	stampa_testo(testo, file, true);

	return static_cast<bool>(file);
}

bool carica_testo(testo_t &testo)
{
	ifstream file(FILENAME);

	if (!static_cast<bool>(file))
		return false;
	
	int N;
	file >> N;
	inizializza_testo(testo, N, file);

	return static_cast<bool>(file);
}

bool testo_in(const testo_t &a, const testo_t &b, bool senza_spazi)
{
	for (int r=0; r<a.n_righe-b.n_righe; r++)
	{
		bool trovate = true;
		for (int c=0; c<b.n_righe; c++)
		{
			int ac=0, bc=0;
			for (int j=0; j<MAXLUN; j++){
				if (senza_spazi)
				{
					while (a.righe[r][ac] == ' ')
						ac++;
					while (b.righe[r][bc] == ' ')
						bc++;
				}
				cout << a.righe[r][ac] << " " << b.righe[c][bc] << endl;
				if (a.righe[r][ac] == '\0' && b.righe[c][bc] == '\0')
					break;
				if (a.righe[r][ac++] != b.righe[c][bc++])
				{
					trovate = false;
					break;
				}
			}
			if (trovate)
				return true;
		}
	}

	return false;
}

bool cerca_righe(const testo_t &testo, const int M)
{
	testo_t da_cercare;
	inizializza(da_cercare);
	inizializza_testo(da_cercare, M, cin);

	if (testo_in(testo, da_cercare, false))
	{
		cout << "Trovate" << endl;
		return true;
	}

	cout << "Non trovate" << endl;
	return false;
}


bool cerca_righe2(const testo_t &testo, const int M){
	testo_t da_cercare;
	inizializza(da_cercare);
	inizializza_testo(da_cercare, M, cin);

	if (testo_in(testo, da_cercare, true))
	{
		cout << "Trovate" << endl;
		return true;
	}

	cout << "Non trovate" << endl;
	return false;
}


int main()
{
	testo_t testo;
	inizializza(testo);

	carica_testo(testo);

	//salva_testo(testo);
	stampa_testo(testo, cout, false);
	cerca_righe(testo, 1);
	cerca_righe2(testo, 1);
	return 0;

	const char menu[] =
		"1. Inizializza testo\n"
		"2. Stampa testo\n"
		"3. Salva testo\n"
		"4. Carica testo\n"
		"5. Cerca righe\n"
		"6. Cerca righe 2\n"
		"7. Esci\n";

	while (true) {
		cout<<menu<<endl;
		int scelta;
		cin>>scelta;

		cout<<endl ; // per il corretto funzionamento del tester

		switch (scelta) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}
