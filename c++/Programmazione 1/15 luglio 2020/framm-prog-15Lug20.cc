#include <iostream>
#include <fstream>

using namespace std;

const char FILENAME[] = "traccia.txt"; 
const int MAXLUN = 50; // lunghezza massima righe

const int M = 3; // Numero di risposte alla domanda

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

struct domanda_t {
	char testo[MAXLUN];
	char risposte[M][MAXLUN];
	int corretta;
};

struct traccia_t {
	domanda_t *domande;
	int n_domande;
};

void init_traccia (traccia_t &traccia) {
	traccia.n_domande = -1;
}

void input_traccia(traccia_t traccia, istream &is, bool is_file)
{
	for (int d=0; d<traccia.n_domande; d++)
	{
		if (!is_file)
			cout << "domanda " << d/*+1*/ <<"-esima : ";
		leggi_riga(is, traccia.domande[d].testo);
		for (int r=0; r<M; r++)
		{
			if (!is_file)
				cout << "\trisposta " << r/*+1*/ << "-esima: ";
			leggi_riga(is, traccia.domande[d].risposte[r]);
		}
		cout << "indice risposta corretta: ";
		is >> traccia.domande[d].corretta;
	}
}

bool alloca_traccia(traccia_t &traccia, const int N)
{
	if (N < 0)
		return false;
	
	if (traccia.n_domande > -1 && N != traccia.n_domande)
		delete [] traccia.domande;

	traccia.domande = new domanda_t[N];
	traccia.n_domande = N;

	return true;
}

bool inizializza_traccia(traccia_t &traccia, const int N)
{
	if (!alloca_traccia(traccia, N))
		return false;
	
	input_traccia(traccia, cin, false);
	return true;
}

void stampa_domanda(const domanda_t &domanda, bool mostra_corretta, ostream &os/*=cout*/, bool is_file/*=false*/)
{
	os << domanda.testo << endl;
	for (int r=0; r<M; r++)
	{
		if (is_file)
			os << '\t' << domanda.risposte[r] << endl;
		else
		{
			if (mostra_corretta && r == domanda.corretta)
				os << "* ";
			else os << "  ";

			os << static_cast<char>('a'+r) << ") " << domanda.risposte[r] << endl;
		}
	}
	if (is_file)
		os << domanda.corretta << endl;
}

void stampa_traccia(const traccia_t &traccia, ostream &os/*=cout*/, bool is_file/*=false*/)
{
	if (is_file)
		os << traccia.n_domande << endl;

	for (int d=0; d<traccia.n_domande; d++)
	{
		if (!is_file)
			cout << d+1 << ". ";
		stampa_domanda(traccia.domande[d], true, os, is_file);
	}
}

bool salva_traccia(const traccia_t &traccia)
{
	ofstream file(FILENAME);

	if (!static_cast<bool>(file))
		return false;
	
	stampa_traccia(traccia, file, true);
	
	return static_cast<bool>(file);
}

bool carica_traccia(traccia_t &traccia)
{
	ifstream file(FILENAME);

	if (!static_cast<bool>(file))
		return false;

	int n_domande;
	file >> n_domande;
	alloca_traccia(traccia, n_domande);
	input_traccia(traccia, file, true);
	
	return static_cast<bool>(file);
}

void fai_domanda(const traccia_t &traccia, const int i)
{
	domanda_t &domanda = traccia.domande[i];
	stampa_domanda(domanda, false, cout, false);
	char risposta;
	cin >> risposta;
	if (risposta == static_cast<char>(domanda.corretta + 'a'))
		cout << "Esatto" << endl;
	else
		cout << "Sbagliato" << endl;
}

void fai_domanda2(const traccia_t &traccia)
{
	int i = rand()%traccia.n_domande; // casiuale da 0 a n_domande-1
	fai_domanda(traccia, i);
}

int main()
{
	traccia_t traccia;
	init_traccia(traccia);

	const char menu[] =
		"1. Inizializza traccia\n"
		"2. Stampa traccia\n"
		"3. Salva traccia\n"
		"4. Carica traccia\n"
		"5. Fai domanda\n"
		"6. Fai domanda 2\n"
		"7. Esci\n";

	while (true) {
		cout<<menu<<endl;
		int scelta;
		cin>>scelta;

		cout<<endl ; // per il corretto funzionamento del tester

		switch (scelta) {
		case 1: // Inizializza traccia
		{
			int N;
			cout << "Numero domande: ";
			cin >> N;
			inizializza_traccia(traccia, N);
		}
			break;
		case 2: // Stampa traccia
			stampa_traccia(traccia, cout, false);
			break;
		case 3: // Salva traccia
			salva_traccia(traccia);
			break;
		case 4: // Carica traccia
			carica_traccia(traccia);
			break;
		case 5: // Fai domanda
		{
			int i;
			cout << "indice domanda i: ";
			cin >> i;
			fai_domanda(traccia, i);
		}
			break;
		case 6: // Fai domanda 2
			fai_domanda2(traccia);
			break;
		case 7: // Esci
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}
