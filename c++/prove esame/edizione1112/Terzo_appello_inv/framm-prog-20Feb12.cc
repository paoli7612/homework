#include <iostream>
#include <fstream>

using namespace std ;

const char FILENAME[] = "vettore.txt";

struct vettore_t{
	int *contenitore;
	int capacita, el;
};

void inizializza(vettore_t &v){
	v.capacita = 0;
	v.el = 0;
}
/*Se il vettore ha capacità nulla, porta a 2 la capacità del
vettore e vi inserisce un solo elemento di valore val. Se invece
il vettore ha capacità maggiore di zero e c'è ancora spazio,
aggiunge il valore val in fondo al vettore*/
bool aggiungi_elemento(vettore_t &v, int val){
	if (v.capacita == 0){
		v.contenitore = new int[2];
		v.contenitore[0] = val;
		v.capacita = 2;
		v.el = 1;
	} else if (v.el < v.capacita){
		v.contenitore[v.el++] = val;
	} else
		return false;
	return true;
}

/*Stampa la capacità del vettore ed i valori degli elementi del vettore, col
formato mostrato nel seguente esempio. Se il vettore ha capacità 4 e contiene i valori
[-5, 10, 56], stampa:
4 [ -5, 10, 56 ]*/
void stampa_vettore(const vettore_t &v){
	cout << v.capacita << " [";
	for (int i=0; i<v.el; i++){
		cout << v.contenitore[i] << ", ";
	}
	cout << "\b\b]" << endl;
}

// Salva il vettore in un file di testo dal nome predefinito
void salva_vettore(const vettore_t &v){
	ofstream file(FILENAME);
	
	file << v.capacita << " " << v.el << endl;
	
	for (int i=0; i<v.el; i++)
		file << v.contenitore[i] << " ";
	
	file.close();
}

// Carica il vettore dal file. Contenuto e capacità precedenti sono persi
void carica_vettore(vettore_t &v){
	ifstream file(FILENAME);
	file >> v.capacita >> v.el;
	v.contenitore = new int[v.capacita];
	for (int i=0; i<v.el; i++)
		file >> v.contenitore[i];
	
	file.close();
}

/*Aggiunge il valore val in fondo al vettore. Se non c'è abbastanza
spazio raddoppia la capacità del vettore prima dell'inserimento.*/
void aggiungi_elemento2(vettore_v &v, int val){
	
}

int main()
{
	vettore_t vettore;
	inizializza(vettore);
	
	const char menu[] =
		"1. Aggiungi elemento\n"
		"2. Stampa vettore\n"
		"3. Salva vettore\n"
		"4. Carica vettore\n"
		"5. Aggiungi elemento con riallocazione\n"
		"6. Elimina elemento\n"
		"7. Partiziona vettore\n"
		"8. Esci\n" ;

	while(true) {
		cout<<menu<<endl ;
		int scelta ;
		cin>>scelta ;
		switch(scelta) {
			int n;
			case 1: // Aggiungi elemento
				cout << "Elemento da aggiungere: ";
				cin >> n;
				if (!aggiungi_elemento(vettore, n))
					cout << "Vettore pieno";
				break ;
			case 2: // Stampa vettore
				stampa_vettore(vettore);
				break ;
			case 3: // Salva vettore
				salva_vettore(vettore);
				break ;
			case 4: // Carica vettore
				carica_vettore(vettore);
				break ;
			case 5:
				break ;
			case 6:
				break ;
			case 7:
				break ;
			case 8:
				return 0 ;
			default:
				cout<<"Scelta errata"<<endl ;
		}
	}
	return 1 ;
}
