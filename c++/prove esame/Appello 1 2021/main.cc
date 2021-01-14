#include <iostream>
#include <fstream>

using namespace std;

const char FILENAME[] = "data.txt";

struct coda_t {
	char* vettore;
	int N;
	int start, el;
};

void init(struct coda_t &c){
	c.vettore = new char[0];
	c.N = 0;
	c.start = 0;
	c.el = 0;
}

char& get(const struct coda_t &c, int i){
	return c.vettore[(i+c.start)%c.N];
}

bool inizializza_coda(struct coda_t &c, const int N){
	if (N < 0) // Inizialzzo a lunghezza negativa?
		return false;

	c.vettore = new char[N];
	c.N = N;
	c.start = 0;
	c.el = 0;
}

void stampa(const struct coda_t &c, ostream out=cout, bool is_file=true){
	if (is_file)
		out << c.N << " " << c.N << endl;
	for (int i=0; i<c.el; i++){
		out << (char)get(c, i) << " ";
	}
}

bool accoda_utente(struct coda_t &c, char s){
	if (c.el == c.N) // Coda piena
		return false;
		
	c.vettore[c.el++%c.N] = s;
}

void salva_coda(const struct coda_t &c){
	ofstream file(FILENAME);
	stampa(c, file, true);
	file.close();
}

int main(){
	
	coda_t c;
	init(c);
	inizializza_coda(c, 10);
	accoda_utente(c, 'A');
	accoda_utente(c, 'B');
	accoda_utente(c, 'A');
	accoda_utente(c, 'A');
	
	stampa(c);
	//salva_coda(c);
	
	return 0;
}
