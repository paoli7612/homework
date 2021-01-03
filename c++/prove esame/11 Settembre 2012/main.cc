// 11 settembre 20012

#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SEQUENZE = 10;
const int MAX_SEQUENZA = 10;

const char FILENAME[] = "data.dat";

struct sequenze_t {
	int mat[MAX_SEQUENZE][MAX_SEQUENZA+1];
	int sequenze = 0;	
};

void aggiungi_sequenza(sequenze_t &s, int* sequ, int len){
	s.mat[s.sequenze][0] = len;
	for (int i=1; i<=len; i++)
		s.mat[s.sequenze][i] = sequ[i-1];
	s.sequenze++;
}

void stampa_insieme(sequenze_t s){
	cout << endl;
	for (int a=0; a<s.sequenze; a++){
		for (int i=1; i<=s.mat[a][0]; i++)
			cout << s.mat[a][i] << " ";
		cout << endl;
	}
	cout << endl;
}

void ask_sequenza(sequenze_t &s){
	if (s.sequenze == MAX_SEQUENZE){
		cout << "Massimo numero sequenze raggiunto" << endl;
		return;
	}
	int len;
	cout << "Lunghezza sequenza: ";
	cin >> len;
	if (len < 1 || len > MAX_SEQUENZA){
		cout << "Lunghezza sequenza non valida" << endl;
		return;
	}
	int* seq = new int[len];
	for (int a=0; a<len; a++){
		cout << "Numero " << a+1 << ": ";
		cin >> seq[a];
	}
	aggiungi_sequenza(s, seq, len);
}

void save(sequenze_t &s){
	ofstream file(FILENAME);
	
	const int SIZE = sizeof(int);
	cout << endl << "SEQUENZE: " << s.sequenze << endl;
	file.write((char*)&s.sequenze, SIZE);
	for (int i=0; i<s.sequenze; i++){
		file.write((char*)&s.mat[i][0], SIZE);
		for (int j=1; j<=s.mat[i][0]; j++){
			file.write((char*)&s.mat[i][j], SIZE);
		}
	}
	
	file.close();
}

void load(sequenze_t &s){
	ifstream file(FILENAME);
	
	const int SIZE = sizeof(int);
	int sequenze;
	file.read((char*)&sequenze, SIZE);

	for (int i=0; i<sequenze; i++){
		int len;
		file.read((char*)&len, SIZE);
		int* seq = new int[len];
		for (int j=0; j<len; j++){
			file.read((char*)&seq[j], SIZE);
		}
		aggiungi_sequenza(s, seq, len);
	}
	
	
	file.close();	
}

void elimina_ultima_sequenze(sequenze_t &s){
	// ELIMINA ULTIMA SEQUENZE se è più lunga di almeno una delle altre sequenze
	int i, len = s.mat[s.sequenze-1][0];
	for (i=0; i<s.sequenze-1; i++){
		if (s.mat[i][0] < len){
			s.sequenze--;
			break;
		}
	}
}

void aggiungi_intersezione(sequenze_t &s){
	if (s.sequenze == 0){
		cout << "Non sono presenti sequenze" << endl;
		return;
	}
	int len_max = s.mat[0][0];
	
	int** seq = new int*[len_max];
	for (int i=0; i<len_max; i++){
		seq[i] = new int[2];
		seq[i][0] = s.mat[0][i+1];
	}
	
	for (int i=1; i<s.sequenze; i++){ // per ogni sequenza indice i
		for (int n=0; n<s.mat[i][0]; n++){ // per ogni numero indice n+1
			for (int j=0; j<len_max; j++){ // per ogni numero della prima sequenza indice j
				if (s.mat[i][n+1] == seq[j][0]){ // se quel numero è compreso nella prima sequenza
					seq[j][1]++;
					
				}
			}
		}
	}
	
	int* fin = new int[len_max];
	int l = 0;
	for (int i=0; i<len_max; i++){
		if (seq[i][1] == s.sequenze-1)
			fin[l++] = seq[i][0];
	}
	aggiungi_sequenza(s, fin, l);
	cout << endl;
	
}

int main(){
	sequenze_t s;
	const char menu[] = 
		"1. Aggiungi sequenza\n"
		"2. Stampa sequenze\n"
		"3. Salva\n"
		"4. Carica\n"
		"5. Elimina ultima sequenza\n"
		"6. Aggiungi intersezione\n"
		"7. Esci";
		
		
	bool run = true;
	while (run){
		int scelta;
		cout << menu << endl;
		cin >> scelta;
		
		switch(scelta){
			case 1: // AGGIUNGI SEQUENZE
				ask_sequenza(s);
				break;
			case 2: // STAMPA SEQUENZE
				stampa_insieme(s);
				break;
			case 3: // SALVA
				save(s);
				break;
			case 4: // CARICA
				load(s);
				break;
			case 5: // ELIMINA ULTIMA SEQUENZE
				elimina_ultima_sequenze(s);
				break;
			case 6: // AGGIUNGI INTERSEZIONE
				aggiungi_intersezione(s);
				break;
			case 7: // ESCI
				run = false;
				break;
			default:
				cout << "Scelta non valida" << endl;
		}
		
	}
		
	return 0;
}
