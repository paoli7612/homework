#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum stato_t {OFF, ON};

const char FILENAME[] = "schermo.txt";
const int N_RIGHE = 5;

struct schermo_t {
	stato_t *pixels[N_RIGHE];
	unsigned int n_colonne;
};

void inizializza_schermo(schermo_t &schermo, unsigned int n_colonne)
{
	for (int y=0; y<N_RIGHE; y++)
	{
		schermo.n_colonne = n_colonne;
		schermo.pixels[y] = new stato_t[n_colonne];
		for (int x=0; x<n_colonne; x++)
			schermo.pixels[y][x] = ON;
	}
}

bool modifica_stato_pixel(schermo_t &schermo, unsigned int riga, unsigned int num_pixel, stato_t stato)
{
	unsigned int &x = num_pixel;
	unsigned int &y = riga;

	if (y >= N_RIGHE || x >= schermo.n_colonne)
		return false;
	
	schermo.pixels[y][x] = stato;
	return true;
}

char char_pixel(stato_t s)
{
	if (s == ON)
		return '*';
	else /*if (s == OFF)*/
		return '_';
}

void stampa_display(schermo_t &schermo, ostream &os/*=cout*/, bool is_file/*=false*/)
{
	if (is_file)
		os << schermo.n_colonne << endl;
		
	for (int y=0; y<N_RIGHE; y++){
		for (int x=0; x<schermo.n_colonne; x++)
		{
			if (is_file)
				os << schermo.pixels[y][x] << " ";
			else
				os << char_pixel(schermo.pixels[y][x]);
		}
	os << endl;
	}
}

void modifica_numero_pixel_per_riga(schermo_t &schermo, int n_colonne)
{
	schermo_t nuovo;
	inizializza_schermo(nuovo, n_colonne);
	for (int y=0; y<N_RIGHE; y++)
		for (int x=0; x<n_colonne && x<schermo.n_colonne; x++)
		{
			nuovo.pixels[y][x] = schermo.pixels[y][x];
		}
	schermo = nuovo;
}

void modifica_stato_display(schermo_t &schermo, istream &is/*=cin*/)
{
	for (int y=0; y<N_RIGHE; y++)
		for (int x=0; x<schermo.n_colonne; x++)
			{
				int s;
				is >> s;
				schermo.pixels[y][x] = static_cast<stato_t>(s);
			}	
}

bool salva_display(schermo_t &schermo)
{
	ofstream file(FILENAME);
	if (!static_cast<bool>(file))
		return false;
	
	stampa_display(schermo, file, true);

	return static_cast<bool>(file);
}

bool carica_display(schermo_t &schermo)
{
	ifstream file(FILENAME);
	if (!static_cast<bool>(file))
		return false;
	
	int N;
	file >> N;
	inizializza_schermo(schermo, N);

	modifica_stato_display(schermo, file);

	return static_cast<bool>(file);
}

bool modifica_stato_riga (schermo_t &schermo, char *sequenza_stati, int n_riga)
{
	for (int i=0; sequenza_stati[i]!='\0'; i++)
	{
		if (sequenza_stati[i] == char_pixel(ON))
			schermo.pixels[n_riga][i] = ON;
		else if (sequenza_stati[i] == char_pixel(OFF))
			schermo.pixels[n_riga][i] = OFF;
		else // un carattere della stringa non corrisponde nè ad ON nè a OFF
			return false;
	}
	// Tutti i caratteri della stringa rappresentavano ON o OFF
	return true;
} 

int main()
{
	schermo_t schermo;
	inizializza_schermo(schermo, 10);

	const char menu[] =
		"1. Modifica stato pixel\n"
		"2. Stampa display\n"
		"3. Modifica numero pixel per riga\n"
		"4. Salva stato display\n"
		"5. Carica stato display\n"
		"6. Modifica stato singola riga\n"
		"7. Modifica stato display\n"
		"8. Esci\n";
	
	while (true) {
		cout<<endl<<menu<<endl;

		int scelta;
		cin>>scelta;
		
		switch (scelta) {

		case 1: // Modifica stato pixel
		{
			cout << "Inserisci n_riga e n_pixel: ";
			unsigned int num_riga, num_pixel;
			cin >> num_riga >> num_pixel;
			cout << "Acceso 1 o spento 0 ? : ";
			int stato;
			cin >> stato;
			modifica_stato_pixel(schermo, num_riga, num_pixel, static_cast<stato_t>(stato));
		}
			break;
		case 2: // Stampa display
			stampa_display(schermo, cout, false);
			break;
		case 3: // Modifica numero pixel per riga 
		{
			int n_pixel;
			cout << "Inserisci il nuovo numero di pixel per riga: ";
			cin >> n_pixel;
			modifica_numero_pixel_per_riga(schermo, n_pixel);
		}
			break;
		case 4: // Salva stato display 
			if (!salva_display(schermo))
				cerr << "Errore nel salvataggio su file" << endl;
			break;
		case 5: // Carica stato display
			if (!carica_display(schermo))
				cerr << "Errore nel caricamento da file" << endl;
			break;
		case 6: // Modifica stato singola riga
		{
			unsigned n_riga;
			cout << "Inserisci stringa: ";
			char *sequenza_stati = new char[schermo.n_colonne];
			cin >> sequenza_stati;
			cout << "Inserisci il numero della riga: ";
			cin >> n_riga;
			modifica_stato_riga(schermo, sequenza_stati, n_riga);
			delete[] sequenza_stati;
		}
			break;
		case 7: // Modifica stato display
			break;
		case 8: // Esci
			return 0;
		default:
			cout<<"Scelta errata"<<endl;
		}
	}
	return 1;
}
