// Appello 1

#include <iostream>
#include <fstream>

using namespace std;

struct coda_t {
	char* vet; // Puntatore a char (array dinamico)
	int N; // lunghezza del vettore
	int s; // indice del vettore da cui comincia la coda
	int u; // numero di utenti in coda
};

// Inizializza coda vuota e lunghezza=0
void inizializza(struct coda_t &c){
	c.vet = new char[0];
	c.N = 0;
	c.N = 0;
}

bool inizializza_coda(struct coda_t &c, int n){
	if (n < 0) // lunghezza coda negativa ?!?!?
		return false;
	
	c.N = n;
	delete[] c.vet; // dealloca la precedente coda
	c.vet = new char[n];
	c.s = 0;
}

// accoda utente codice u
bool accoda_utente(struct coda_t &c, char u){
	if (c.N == c.u) // Coda piena
		return false;
	
	c.vet[(c.s+(c.u++))%c.N] = u;
}

void stampa_coda(const struct coda_t &c, ostream &out=cout, bool isfile=false){
	if (isfile)
		out << c.N << " " << c.u << endl;
	
	for (int i=c.s; i<c.s+c.u; i++)
		cout << c.vet[i%c.N] << " ";
	
	out << endl;
}

void scambia(char &a, char &b){
	char t = a;
	a = b;
	b = t;
}

void anticipa_servizio(struct coda_t &c, char s){

}

bool servi_prossimo_utente(struct coda_t &c){
	if (c.u == 0) // Nessun utente in coda
		return false;
		
	c.s = (c.s+1)%c.N;
	c.u--;
}

int main(){
	
	coda_t c;
	inizializza(c);
	inizializza_coda(c, 10);
	accoda_utente(c, 'A');
	accoda_utente(c, 'C');
	accoda_utente(c, 'D');
	accoda_utente(c, 'A');
	accoda_utente(c, 'A');
	accoda_utente(c, 'C');
	accoda_utente(c, 'D');
	accoda_utente(c, 'A');
	stampa_coda(c);
	
	servi_prossimo_utente(c);
	stampa_coda(c);
	
	anticipa_servizio(c, 'A');
	stampa_coda(c);
	
	return 0;
}
