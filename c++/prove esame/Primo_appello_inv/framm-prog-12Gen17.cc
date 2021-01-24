#include <iostream>
#include <fstream>

using namespace std ;

const char FILENAME[] = "insieme.txt";
const int MAX_LUNGHEZZA_CODA = 10; 

struct insieme_t {
	int *code; // ogni posizione rappresenta quanti utenti ci sono in coda
	
}

int main()
{
	const char menu[] =
		"1. Inizializza code\n"
		"2. Accoda utente\n"
		"3. Servi prossimo utente\n"
		"4. Stampa stato code\n"
		"5. Salva stato code\n"
		"6. Carica stato code\n"
		"7. Attiva modalita' numeri limitati\n"
		"8. Esci\n" ;

	while (true) {
		cout<<menu<<endl ;

		int scelta ;
		cout<<"Scelta: " ;
		cin>>scelta ;

		switch (scelta) {
		case 1:
			break ;
		case 2:
			break ;
		case 3:
			break ;
		case 4:
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
			cout<<"Scelta sbagliata"<<endl ;
		}
	}

	return 1 ;
}
