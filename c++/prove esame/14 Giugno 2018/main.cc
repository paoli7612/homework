#include <iostream>
#include <fstream>

using namespace std;

typedef char Nome;

const char FILENAME[] = "insieme.dat";

const char MAX_PACCHETTI = 'z'-'A'+1;

struct insieme_t {
	int N;
	int *dipendenze;
};

char nome(int i){
	return static_cast<char>(i + 'A');
}

void init(insieme_t &insieme)
{
	insieme.N = 0;
	insieme.dipendenze = new int[0];
}

bool reinizializza_insieme(insieme_t &insieme, const int N)
{
	if (N < 0)
		return false;

	delete [] insieme.dipendenze;
	insieme.dipendenze = new int[N];

	for (int i=0; i<N; i++)
		insieme.dipendenze[i] = MAX_PACCHETTI;
		
	insieme.N = N;

	return true;
}

bool imposta_dipendenza(insieme_t &insieme, const int p1, const int p2)
{
	if (p1 < 0 || p2 < 0 || p1 >= insieme.N || p2 >= insieme.N)
		return false;

	insieme.dipendenze[p1] = p2;
	return true;
}

bool imposta_dipendenza(insieme_t &insieme, const char p1, const char p2)
{
	return imposta_dipendenza(insieme, nome(p1), nome(p2));
}

void stampa_dipendenze(const insieme_t &insieme)
{
	for (int i=0; i<insieme.N; i++)
	{
		cout << nome(i);
		if (insieme.dipendenze[i] != MAX_PACCHETTI)
			cout << " -> " << nome(insieme.dipendenze[i]);
		cout << endl;
	}
}

bool salva(const insieme_t &insieme)
{
	ofstream file(FILENAME);

	if (!file)
		return false;

	file.write((char*)&insieme.N, sizeof(int));

	for (short int i=0; i<insieme.N; i++)
		file.write((char*)&insieme.dipendenze[i], sizeof(int));

	file.close();
	return static_cast<bool>(file);
}

bool carica(insieme_t &insieme)
{
	ifstream file(FILENAME);

	if (!file)
		return false;

	int N;
	file.read((char*)&N, sizeof(int));

	reinizializza_insieme(insieme, N);

	for (int i=0; i<N; i++)
		file.read((char*)&insieme.dipendenze[i], sizeof(int));

	file.close();
	return static_cast<bool>(file);
}

void stampa_catena_dipendenze(insieme_t &insieme, int p, int n, bool first=true)
{
	if (n == -1)
		return;

	if (!first)
		cout << " -> ";

	cout << nome(p);

	if (insieme.dipendenze[p] != MAX_PACCHETTI)
		stampa_catena_dipendenze(insieme, insieme.dipendenze[p], n-1, false);
}

int main(int argc, char** argv)
{
	insieme_t insieme;
	init(insieme);

	const char menu[] =
		"1. Inizializza insieme\n"
		"2. Imposta dipendenza\n"
		"3. Stampa dipendenze\n"
		"4. Salva insieme\n"
		"5. Carica insieme\n"
		"6. Stampa catena delle dipendenze\n"
		"7. Esci\n";

	bool running = true;
	while (running) {
		cout<<menu<<endl;

		int scelta;
		cin >> scelta;

		switch (scelta) {
			case 1: // inizializza
			{
				int N;
				cout << "N: ";
				cin >> N;

				reinizializza_insieme(insieme, N);
			}
				break;
			case 2: // imposta dipendenze
			{
				int p1, p2;
				cout << "Inserisci l'indice del pacchetto (p1): ";
				cin >> p1;
				cout << "Inserisci l'indice del pacchetto (p2): ";
				cin >> p2;

				imposta_dipendenza(insieme, p1, p2);
			}
				break;
			case 3: // stampa insieme
				stampa_dipendenze(insieme);
				break;
			case 4: // salva insieme
				if (!salva(insieme))
					cout << "Errore salvataggio" << endl;
				break;
			case 5: // carica insieme
				if (!carica(insieme))
					cout << "Errore caricamento" << endl;
				break;
			case 6: // stampa catena delle dipendenze
			{
				int n, p;
				cout << "Inserisci l'indice del primo pacchetto (p): ";
				cin >> p;
				cout << "Inserisci il numero massimo di dipendenze (n): ";
				cin >> n;

				stampa_catena_dipendenze(insieme, p, n);
				cout << endl;
			}
				break;
			case 7: // esci
				running = false;
				break;
			default:
				cout << "Scelta errata" << endl;
		}
	}
	return 0;
}
