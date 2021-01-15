#include <iostream>
#include <fstream>

using namespace std;

const char NOMEFILE[] = "coda.txt";

struct coda_t {
	char *utenti; 
	int inizio, quanti, N;
};

void inizializza(coda_t &coda){
	coda.quanti = 0;
	coda.N = 0;
}

bool reinizializza (coda_t &c, int N){
	if (N < 0) // N negativo
		return false;

	if (N != c.N && c.N > 0) {
		delete[] c.utenti;
		c.N = 0;
	}

	if (c.N == 0 && N > 0)
		c.utenti = new char[N];

	c.inizio = 0;
	c.quanti = 0;
	c.N = N;

	return true;
}

bool accoda_utente(coda_t &c, char codice){
	if (c.quanti == c.N || // Coda piena
	    codice < 'A' || codice > 'Z') // Codice !=lettera
		return false;

	c.utenti[(c.inizio+c.quanti++)%c.N] = codice;

	return true;
}

bool scrivi_coda(const coda_t &c, ostream &os, bool su_file){
	if (su_file)
		os<<c.N<<' '<<c.quanti<<endl;

	for (int i = 0 ; i < c.quanti ; i++) {
		os<<c.utenti[(c.inizio + i)%c.N] << ' ';
	}

	os<<endl;

	return static_cast<bool>(os);
}

bool carica_coda(coda_t &c){
	ifstream f(NOMEFILE);

	if (!f)
		return false;

	int N;
	f >> N;

	if (!reinizializza(c, N))
		cout<<"Reinizializzazione fallita"<<endl;

	int quanti;
	f >> quanti;

	for (int i = 0 ; i < quanti ; i++) {
		char s;
		f>>s;
		accoda_utente(c, s);
	}

	return static_cast<bool>(f);
}


bool servi_prossimo_utente(coda_t &c){
	if (c.quanti == 0) // Coda vuota
		return false;

	c.inizio = (c.inizio + 1) % c.N;
	c.quanti--;

	return true;
}


void sposta(coda_t &c, int i, int j){
	char originale = c.utenti[j];

	for (int k = j ; k > i ; k--)
		c.utenti[k] = c.utenti[k-1];

	c.utenti[i] = originale;
}


void anticipa_servizio(coda_t &c, char s){
	int inizio_ricerca = c.inizio;

	for (int i = 1 ; i < c.quanti ; i++) {
		int pos = (c.inizio + i) % c.N;

		if (c.utenti[i] != s)
			continue;

		for ( ; inizio_ricerca < i ; inizio_ricerca++)
			if (c.utenti[inizio_ricerca] != s) {
				sposta(c, inizio_ricerca, pos);
				inizio_ricerca =
					(inizio_ricerca + 1) % c.N;
				break;
			}
	}
}

int main()
{
	coda_t coda;
	inizializza(coda);
	
	carica_coda(coda);
	scrivi_coda(coda,cout, false);
	
	anticipa_servizio(coda, 'A');
	scrivi_coda(coda, cout, false);
	return 0;

	const char menu[] =
		"1. Reinizializza coda\n"
		"2. Accoda utente\n"
		"3. Stampa coda\n"
		"4. Salva coda\n"
		"5. Carica coda\n"
		"6. Servi prossimo utente\n"
		"7. Anticipa servizio\n"
		"8. Esci\n";

	while (true) {
		cout<<menu<<endl;
		int scelta;
		cin>>scelta;

		cout<<endl ; // per il corretto funzionamento del tester

		switch (scelta) {
		case 1: {
			cout<<"Lunghezza massima della coda: ";
			int N;
			cin>>N;

			if (!reinizializza(coda, N))
				cout<<"Inizializzazione fallita"<<endl;
		}
			break;
		case 2: {
			cout<<"Codice del servizio: ";
			char c;
			cin>>c;

			if (!accoda_utente(coda, c))
				cout<<"Accodamento fallito"<<endl;
		}
			break;
		case 3:
			scrivi_coda(coda, cout, false);
			break;
		case 4: {
			ofstream f(NOMEFILE);
			if (!scrivi_coda(coda, f, true))
				cout<<"Salvataggio fallito"<<endl;
			f.close();
		}
			break;
		case 5:
			if (!carica_coda(coda))
				cout<<"Caricamento fallito"<<endl;
			break;
		case 6:
			if (!servi_prossimo_utente(coda))
				cout<<"Servizio fallito"<<endl;
			break;
		case 7: {
			cout<<"Inserisci codice di servizio: "<<endl;
			char c;
			cin>>c;

			anticipa_servizio(coda, c);
		}
			break;
		case 8:
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}
