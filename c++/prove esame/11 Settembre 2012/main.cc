#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    const char menu[] =
		"1. Aggiungi sequenza all'insieme\n"
		"2. Stampa insieme delle sequenze\n"
		"3. Salva insieme delle sequenze\n"
		"4. Carica insieme delle sequenze\n"
		"5. Aggiungi sequenza intersezione all'insieme\n"
		"6. Esci\n";

	bool running = true;
    while(running) {
		cout << menu << endl;
		int scelta;
		cin >> scelta;
		switch(scelta) {
			case 1: // Aggiungi sequenza all'insieme
				break;
			case 2: // Stampa insieme delle sequenze
				break;
			case 3: // Salva insieme delle sequenze
				break;
			case 4: // Carica insieme delle sequenze
				break;
			case 5: // Aggiungi sequenza intersezione all'insieme
				break;
			case 6: // Esci
				running = false;
				break;
			default:
				cout << "Scelta errata" << endl;
		}
    }
}
