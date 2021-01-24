#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std ;

const char FILENAME[] = "quadrato.txt";
const int WIDTH = 20, HEIGHT = 15;

struct coord_t { int x, y; };

struct quadrato_t {
	coord_t angolo;
	int dim;
	char car;
};

struct area_t {
	quadrato_t quadrato;
	bool is_presente; 	// Vero -> un quadrato e' presente
						// Falso -> l'area e' vuota
};
void init(area_t &area){
	area.is_presente = false;
}
bool in_area(const coord_t c){
	if (c.x*c.y < 0)
		return false;
	if (c.x >= WIDTH || c.y >= HEIGHT)
		return false;
	return true;
}
bool in_quadrato(quadrato_t q, coord_t p){
	if (q.angolo.x > p.x && (q.angolo.x + q.dim) <= p.x) // X fuori dal quadrato
		return false;
	if (q.angolo.y > p.y && (q.angolo.y + q.dim) <= p.y) // Y fuori dal quadrato
		return false;
	return true;
}

bool crea_quadrato(area_t &area, const coord_t angolo, const int dim, const char car)
{
	if (!in_area(angolo))
		return false; // Partenza fuori dall'area
	if (!in_area({angolo.x+dim, angolo.y+dim}))
		return false; // Partenza + dim fuori dall'area

	// ok possiamo crearne uno nuovo
	area.quadrato.angolo = angolo;
	area.quadrato.dim = dim;
	area.quadrato.car = car;

	area.is_presente = true;

	return true;
}

void stampa_area(const area_t &area)
{

	if (!area.is_presente)
		return;

	for (int y=0; y<HEIGHT; y++)
	{
		for (int x=0; x<WIDTH; x++)
		{
			if (x >= area.quadrato.angolo.x && x < area.quadrato.angolo.x + area.quadrato.dim &&
				y >= area.quadrato.angolo.y && y < area.quadrato.angolo.y + area.quadrato.dim)
				cout << area.quadrato.car << " ";
			else
				cout << "  ";
		}
		cout << endl;
	}
}

bool salva_area(const area_t &area)
{
	ofstream file(FILENAME);
	
	if (!file)
		return false;

	file.write((char*)&area.quadrato, sizeof(quadrato_t));

	file.close();
	return (bool)file;
}

bool carica_area(area_t &area)
{
	ifstream file(FILENAME);

	if (!file)
		return false;
	
	file.read((char*)&area.quadrato, sizeof(quadrato_t));

	area.is_presente = true;

	file.close();
	return (bool)file;
}

bool modifica_quadrato(area_t &area, coord_t punto, coord_t angolo, const int dim, const char car)
{
	if (area.is_presente)
	{
		if (!in_area(punto))
			return false;
		
		if (!in_quadrato(area.quadrato, punto))
			return false;
	}
	

	crea_quadrato(area, angolo, dim, car);

	return true;
}

int main()
{
	area_t area;
	init(area);

	const char menu[] =
		"1. Crea quadrato\n"
		"2. Stampa area\n"
		"3. Salva area\n"
		"4. Carica area\n"
		"5. Modifica quadrato\n"
		"6. Riempi sottoarea\n"
		"7. Stampa area 2\n"
		"8. Esci\n" ;

	while (true) {
		cout<<menu<<endl ;
		int scelta ;
		cin>>scelta ;

		switch(scelta) {
		case 1: // Crea quadrato
			{
				coord_t angolo;
				cout << "Inserisci le coordinate del angolo di partenza: ";
				cin >> angolo.x >> angolo.y;

				int dim;
				cout << "Inserisi le dimensioni del quadrato: ";
				cin >> dim;

				char car;
				cout << "Inserisci il carattere con cui riempire il quadrato: ";
				cin >> car;

				if (!crea_quadrato(area, angolo, dim, car))
					cout << "Qualcosa è andato storto" << endl;
			}
			break ;
		case 2: // Stampa area
			stampa_area(area);
			break ;
		case 3: // Salva area
			salva_area(area);
			break ;
		case 4: // Carica area
			carica_area(area);
			break ;
		case 5: // Modifica quadrato
		{
			coord_t punto, angolo;
			cout << "Inserisci le coordinate del punto: ";
			cin >> punto.x >> punto.y;

			cout << "Inserisci le coordinate del angoolo: ";
			cin >> angolo.x >> angolo.y;

			int dim;
			cout << "Inserisi le dimensioni del quadrato: ";
			cin >> dim;

			char car;
			cout << "Inserisci il carattere con cui riempire il quadrato: ";
			cin >> car;
		
			if (!modifica_quadrato(area, punto, angolo, dim, car))
				cout << "Punto interno al quadrato gia esistente" << endl;

		}
			break ;
		case 6: // Riempi sottoarea
			break ;
		case 7: // Stampa area 2
			break ;
		case 8: // Esci
			return 0 ;
		default:
			cout<<"Scelta errata"<<endl ;
		}
	}


}


