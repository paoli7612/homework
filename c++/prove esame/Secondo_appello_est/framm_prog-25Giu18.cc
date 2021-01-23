#include <iostream>
#include <fstream>

using namespace std;

const char FILENAME[] = "insieme.txt";

struct insieme_t {
	int N;

	int* occorrenze;
	int* codici;
	int n_codici;

	bool init; // true/false se è gia stato "inizializzato"
};

insieme_t crea_insieme(const int N)
{
	if (N <= 0)
		throw "N insieme negativa o nulla";

	insieme_t insieme;
	insieme.N = N;
	insieme.n_codici = 0;
	insieme.codici = new int[N];
	insieme.occorrenze = new int[N];

	for (int i=0; i<N; i++)
	{
		insieme.occorrenze[i] = 0;
		insieme.codici[i] = 0;
	}

	return insieme;
}

void dealloca_insieme(insieme_t &insieme)
{
	delete [] insieme.codici;
	delete [] insieme.occorrenze;
}

bool aggiungi_codice(insieme_t &insieme, const int c)
{
	if (!insieme.init)
		return false;

	if (insieme.n_codici == insieme.N)
		return false;
	
	for (int i=0; i<insieme.n_codici; i++)
		if (insieme.codici[i] == c)
		{
			insieme.occorrenze[i]++;
			return true;
		}

	// nuovo codice
	insieme.codici[insieme.n_codici] = c;
	insieme.occorrenze[insieme.n_codici++] = 1;
	return true;
}

void stampa_insieme(const insieme_t &insieme, ostream &out=cout, bool is_file=false)
{
	if (!insieme.init)
		return;

	if (is_file)
		out << insieme.N << " " << insieme.n_codici << endl;

	for (int i=0; i<insieme.n_codici; i++)
	{
		if (is_file)
			out << insieme.codici[i] << " " << insieme.occorrenze[i] << endl;
		else
			out << insieme.codici[i] << ": " << insieme.occorrenze[i] << endl;
	}
}

bool salva_insieme(const insieme_t &insieme)
{
	ofstream file(FILENAME);

	if (!file)
		return false;

	stampa_insieme(insieme, file, true);

	return static_cast<bool>(file);
}

bool carica_insieme(insieme_t &insieme)
{
	ifstream file(FILENAME);

	if (!file)
		return false;

	int N;
	file >> N;
	insieme = crea_insieme(N);


	file >> insieme.n_codici;
	for (int i=0; i<insieme.n_codici; i++)
	{
		file >> insieme.codici [i] >> insieme.occorrenze[i];
	}

	insieme.init = true;

	file.close();
	return static_cast<bool>(file);
}

int main()
{
	insieme_t insieme;
	insieme.init = false;

	const char menu[] =
		"1. Crea insieme\n"
		"2. Aggiungi codice\n"
		"3. Stampa insieme\n"
		"4. Salva insieme\n"
		"5. Carica insieme\n"
		"6. Stampa intersezione\n"
		"7. Esci\n";

	while (true) {
		cout<<menu<<endl;

		int scelta;
		cin>>scelta;

		switch (scelta) {
		case 1:
			{
				int N;
				cout << "Inserisci N: ";
				cin >> N;

				insieme = crea_insieme(N);
			}
			break;
		case 2:
			{
				int c;
				cout << "Insersci codice: ";
				cin >> c;

				aggiungi_codice(insieme, c);
			}
			break;
		case 3:
			stampa_insieme(insieme);
			break;
		case 4:
			if (!salva_insieme(insieme))
				cout << "Errore nel salvataggio" << endl;
			break;
		case 5:
			if (!carica_insieme(insieme))
				cout << "Errore nel caricamento" << endl;
			break;
		case 6:
			break;
		case 7:
			return 0;
		default:
			cout<<"Scelta sbagliata"<<endl;
		}
	}

	return 1;

}
