#include <iostream>
#include <fstream>

using namespace std;

const char FILENAME[] = "coda.txt";

struct coda_t {
	char *vettore;
	int N; // len vettore
	int index;
	int el;
};
void inizializza(coda_t &coda)
{
	coda.N = 0;
}

bool inizializza_coda(coda_t &coda, const int N)
{
	if (N < 0)
		return false;
	
	if (coda.N != 0 && coda.N != N){
		delete [] coda.vettore;
	}

	coda.vettore = new char[N];
	coda.N = N;
	coda.index = 0;
	coda.el = 0;

	return true;
}

void stampa_coda(const coda_t &coda, ostream &os/*=cout*/, bool is_file/*=false*/)
{
	if (is_file)
		os << coda.N << " " << coda.el << endl;

	for (int i=0; i<coda.el; i++)
	{
		int indice = (i + coda.index)%coda.N;
		os << coda.vettore[indice] << " ";
	}

	if (!is_file)
		os << endl;	
}

bool attesta_utente(coda_t &coda, const char c)
{
	if (coda.el == coda.N)
		return false;

	if (coda.index == 0)
		coda.index = coda.N;

	coda.vettore[--coda.index] = c;
	coda.el++;

	return true;
}


bool accoda_utente(coda_t &coda, const char c)
{
	if (coda.el == coda.N)
		return false;

	coda.vettore[(coda.index + coda.el++)%coda.N] = c;
	return true;
}

bool servi_prossimo_utente(coda_t &coda)
{
	if (coda.el == 0)
		return false;

	coda.index = (coda.index+1)%coda.N;
	coda.el--;

	return true;	
}

bool salva(const coda_t &coda)
{
	ofstream file(FILENAME);

	if (!file)
		return false;
	
	stampa_coda(coda, file, true);

	return static_cast<bool>(file);
}

bool carica(coda_t &coda)
{
	ifstream file(FILENAME);

	if (!file)
		return false;
	
	int N, el;
	file >> N >> el;
	inizializza_coda(coda, N);
	
	for (int i=0; i<el; i++)
	{
		char a;
		file >> a;
		accoda_utente(coda, a);
	}

	return static_cast<bool>(file);
}

void anticipa_servizio(coda_t &coda, const char c)
{
	coda_t nuova;
	inizializza(nuova);
	inizializza_coda(nuova, coda.N);

	for (int i=0; i<coda.el; i++)
	{
		char servizio = coda.vettore[(i+coda.index)%coda.N];
		if (servizio == c)
			attesta_utente(nuova, servizio);
		else
			accoda_utente(nuova, servizio);
	}
	stampa_coda(nuova, cout, false);
}

int main()
{
	coda_t coda;
	inizializza(coda);

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
		case 1: // Reinizializza coda
		{
			int N;
			cin >> N;
			inizializza_coda(coda, N);
		}
			break;
		case 2: // Accoda utente
		{
			char c;
			cin >> c;
			accoda_utente(coda, c);
		}
			break;
		case 3: // Stampa coda
		{
			stampa_coda(coda, cout, false);
		}
			break;
		case 4: // Salva coda
			salva(coda);
			break;
		case 5: // Carica coda
			carica(coda);
			break;
		case 6: // Servi prossimo utente
			servi_prossimo_utente(coda);
			break;
		case 7: // Anticipa servizio
		{
			char c;
			cin >> c;
			anticipa_servizio(coda, c);
		}
			break;
		case 8: // Esci
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}

	return 1;
}
