#include <iostream>
#include <fstream>

using namespace std ;

const char FILENAME[] = "biblioteca.txt";

const int MAX_SCAFFALI = 10;
const int MAX_LIBRI = 5;
const int M = 10; // max len titolo libro

enum argomento {NARRATIVA, SCIENZE, STORIA};


// descrittore libto
struct libro_t {
	argomento arg;
	char titolo[M];
};

// descrittore scaffale
struct scaffale_t {
	libro_t libri[MAX_LIBRI];
	int N;
};

// descrittore biblioteca
struct biblioteca_t {
	scaffale_t scaffali[MAX_SCAFFALI];
	int N;
};

// init biblioteca: 1 scaffale vuoto
void inizializza(struct biblioteca_t &b){
	// 1 scaffale
	b.N = 1;
	// ...vuoto
	b.scaffali[0].N = 0;	
}

// tutti i libri/scaffali persi.. inizzializza la biblioteca b a n scaffali vuoti
bool riconfigura_scaffali(struct biblioteca_t &b, const int n){
	if (n < 0 || n >= MAX_SCAFFALI){
		cout << "Impossibile riconfigurare gli scaffali" << endl;
		return false;
	}	
	
	// n scaffali
	b.N = n;
	// ...vuoti
	for (int i=0; i<n; i++){
		b.scaffali[i].N = 0;
	}
}

// chiede argomento (libitato da 1 a 3)
argomento chiedi_argomento(){
	int i;
	do {
		cout << "Inserisci genere (1: narrativa, 2: scienza, 3: storia)";
		cin >> i;
	} while (i < 1 || i > 3);
	return (argomento)(i-1);
}

// chiede titolo e argomento e ritorna libro
libro_t chiedi_libro(const struct biblioteca_t &b){
	libro_t libro;
	cout << "Inserisci titiolo: ";
	cin >> libro.titolo;
	
	libro.arg = chiedi_argomento();
	return libro;
}

// Chiedi numero di scaffale (esistente in b)
int chiedi_scaffale(const struct biblioteca_t &b){
	int i;
	do {
		cout << "Inserisci il numero dello scaffale ( da 0 a " << b.N << " ): ";
		cin >> i;
	} while (i < 0 || i >= b.N);
	
	return i; 
}

// Chiedi numero di scaffali (no limiti)
int chiedi_scaffali(){
	int a;
	cout << "Numero scaffali? " ;
	cin >> a;
	return a;
}

// Vero se le due "stringhe" sono uguali
bool equals(char a[M], char b[M]){
	for (int i=0; a[i]!='\0'; i++)
		if (a[i] != b[i])
			return false;
	return true;
}

// Vero se i due libri sono uguali
bool equals_libri(libro_t l1, libro_t l2){
	if (l1.arg != l2.arg)
		return false;
	
	return equals(l1.titolo, l2.titolo);
}

// Inserisce il libro l nello scaffale s (se non ci sono libri uguali)
bool inserisci_libro(struct scaffale_t &s, libro_t l){
	for (int i=0; i<s.N; i++){
		if (equals_libri(s.libri[i], l))
			return false;
	}
	
	if (s.N == MAX_LIBRI){
		cout << "Scaffale pieno" << endl;
		return false;
	}
	
	s.libri[s.N++] = l;
	return true;
}

// Inserisce il libro l nello scaffale a indice i (se non ci sono libri uguali)
bool inserisci_libro(struct biblioteca_t &b, const int i, libro_t l){
	if (i < 0 || i >= b.N){
		cout << "Indice non valido" << endl;
		return false;
	}
	return inserisci_libro(b.scaffali[i], l);
}

// Stampa libro l
void stampa_libro(libro_t l, ostream &os){
	os << l.titolo << " ";
		switch (l.arg){
			case NARRATIVA: os << "Narrativa"; break;
			case SCIENZE: os << "Scienza"; break;
			case STORIA: os << "Storia"; break;
		}
		os << endl;
}

// Stampa libri dello scaffale
void stampa_scaffale(const struct scaffale_t &s, ostream &os){
	for (int i=0; i<s.N; i++){
		stampa_libro(s.libri[i], os);
	}
}

// Stampa lista di libri sul ostream os (se è un file stampa prima il numero dei libri)
void stampa_scaffale(const struct biblioteca_t &b, int i, ostream &os, bool is_file){
	if (is_file)
		os << b.scaffali[i].N << endl;
	stampa_scaffale(b.scaffali[i], os);
}

// Stampa tutto sul ostream (se è file stampa anche numero di scaffali e di libri)
void stampa(const struct biblioteca_t &b, ostream &os, bool is_file){
	if (is_file)
		os << b.N << endl;
	for (int i=0; i<b.N; i++){
		stampa_scaffale(b, i, os, is_file);
	}
}

// Stampa tutto su un file (In maniera piu comoda di quando stampo su stdout
void salva(const struct biblioteca_t &b){
	ofstream file(FILENAME);
	stampa(b, file, true);
	file.close();
}

// Ricarica tutto dal file
void carica(struct biblioteca_t &b){
	ifstream file(FILENAME);
	int n, i;
	file >> n;
	riconfigura_scaffali(b, n);
	for (int a=0; a<5; a++){
		file >> i;
		b.scaffali[a].N = i;
		for (int c=0; c<i; c++){
			file >> b.scaffali[a].libri[c].titolo;
			int ai;
			file >> ai;
			b.scaffali[a].libri[c].arg = (argomento)ai;
		}
	}
	file.close();
}

// Ritorna la frazione del argomento nello scaffale
float frazione_argomento(const struct scaffale_t &s, argomento arg){
	int n = 0;
	for (int i=0; i<s.N; i++)
		if (s.libri[i].arg == arg)
			n++;
			
	return (float)n/(float)s.N; // ...
}

// Ritorna la frazione del argomento nello scaffale ad indice i
float frazione_argomento(const struct biblioteca_t &b, int i, argomento arg){
	return frazione_argomento(b.scaffali[i], arg);
}

// Stampa le frazioni del argomento arg su tutti gli scaffali
void distribuzione_argomenti(const struct biblioteca_t &b, argomento arg){
	for (int i=0; i<b.N; i++){
		cout << "scaffale " << (char)(i+'A') << ": " << frazione_argomento(b.scaffali[i], arg) << endl;;
	}	
}

void libri_ripetuti(const struct biblioteca_t &b){
	for (int s=0; s<b.N; s++)
		for (int l=0; l<b.scaffali[s].N)
}

int main(){
	
	biblioteca_t b;
	inizializza(b);

    const char menu[] =
		"\t1. Riconfigura scaffali\n"
		"\t2. Inserisci libro\n"
		"\t3. Stampa contenuto scaffale\n"
		"\t4. Salva\n"
		"\t5. Carica\n"
		"\t6. Stampa frazione argomento\n"
		"\t7. Stampa distribuzione argomenti\n"
		"\t8. Stampa titoli ripetuti\n"
		"\t9. Esci\n" ;


	bool run = true;
    while(run) {
		cout<<endl<<menu<<endl;
		
		int scelta;
		cin>>scelta;
		
		switch(scelta){
			case 1: // Riconfigura scaffali
			    riconfigura_scaffali(b, chiedi_scaffali());
			    break;
			case 2: // Inserisci libro
			    if (!inserisci_libro(b, chiedi_scaffale(b), chiedi_libro(b)))
			    	cout << "Qualcosa è andato storto" << endl;
				break;
			case 3: // Stampa contenuto scaffale
				stampa_scaffale(b, chiedi_scaffale(b), cout, false);
			    break ;
			case 4: // Salva
				salva(b);
			    break ;
			case 5: // Carica
				carica(b);
			    break ;
			case 6: // Stampa frazione argomento
			    cout << frazione_argomento(b, chiedi_scaffale(b), chiedi_argomento());
				break;
			case 7: // Stampa distribuzione argomenti
				distribuzione_argomenti(b, chiedi_argomento());
			    break ;
			case 8: // Libri ripetuti
				libri_ripetuti(b);
			    break ;
			case 9:
			    run = false;
			    break;
			default:
			    cout << "Scelta non valida" << endl ;
			}
	    }

    return 0;
}
