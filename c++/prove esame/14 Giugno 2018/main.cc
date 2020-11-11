#include <iostream>

using namespace std;

typedef char Nome;

struct Pacchetto {
	Nome nome;
	Pacchetto* dipendente = NULL;
};

struct Dipendenze {
	int N;
	Pacchetto* pacchetti;
	bool init = false;
} dipendenze;

Pacchetto* cerca(Nome nome){
	for (int i=0; i<dipendenze.N; i++){
		Pacchetto* p = &dipendenze.pacchetti[i];
		if (p->nome == nome)
			return p;
	}
	return &dipendenze.pacchetti[0];
}

Nome chiedi_pacchetto(Nome n = ('A'-1)){
	Nome nome;
	do {
		cout << "Inserisci il nome del pacchetto(dalla A alla " << (char)(dipendenze.N + 'A' - 1);
		if (n != ('A'-1))
			cout << ", non " << n;
		cout << "): ";
		cin >> nome;
	} while (nome < 'A' || nome > ('A' + dipendenze.N) || nome == n);
	return nome;
}

void inizializza(int n){
	dipendenze.N = n;
	dipendenze.pacchetti = new Pacchetto[n];
	dipendenze.init = true;
	for (int i=0; i<n; i++)
		dipendenze.pacchetti[i].nome = 'A' + i;
}

void imposta_dipendenza(Nome nome1, Nome nome2){
	Pacchetto *a = cerca(nome1);
	Pacchetto *b = cerca(nome2);
	a->dipendente = b;
}

void stampa(){
	for (int i=0; i<dipendenze.N; i++){
		Pacchetto* p = &dipendenze.pacchetti[i];
		cout << p->nome;
		if (p->dipendente != NULL)
			cout << " -> " << p->dipendente->nome;
		cout << endl;
	}
}

void stampa_catena(Pacchetto* current){
	cout << current->nome;
	if (current->dipendente != NULL){
		cout << " -> ";
		stampa_catena(current->dipendente);
	}
}

void stampa_catena_delle_dipendenze(Nome start){
	Pacchetto* p = cerca(start);
	stampa_catena(p);
	cout << endl;
}

int main(int argc, char** argv){
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
		cin>>scelta;

		if (scelta > 1 && scelta < 7 && !dipendenze.init && scelta != 4){
            cout << "Insieme non inizializato" << endl;
            continue;
        }

		switch (scelta) {
			case 1: // inizializza
				int n;
				cout << "Inserisci il numero di dipendenze dell'insieme: ";
				cin >> n;
				inizializza(n);
				break;
			case 2: // imposta dipendenze
				char n1, n2;
				cout << "Inserisci il nome del pacchetto" << endl;
				n1 = chiedi_pacchetto();
				cout << "Inserisci il nome del pacchetto a cui farlo dipendere" << endl;
				n2 = chiedi_pacchetto(n1);
				imposta_dipendenza(n1, n2);
				break;
			case 3: // stampa insieme
				stampa();
				break;
			case 4: // salva insieme
				break;
			case 5: // carica insieme
				break;
			case 6: // stampa catena delle dipendenze
				Nome n3;
				cout << "Inserisci il nome da cui partire" << endl;
				n3 = chiedi_pacchetto();
				stampa_catena_delle_dipendenze(n3);
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
