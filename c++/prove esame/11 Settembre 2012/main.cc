#include <iostream>
#include <fstream>

using namespace std;

const int MAX_NUM = 10; 
const int MAX_SEQ = 5;  
const char FILENAME[] = "data.dat";

struct Sequenza {
    int vettore[MAX_NUM];
    int N;	
};

struct Insieme {
    Sequenza sequenze[MAX_SEQ];
    int num_seq = 0;		
};

void ask_seq(Sequenza &s) {
	int i;
	cout << "Quanti numeri vuoi inserire in questa Sequenza? ->";
	cin >> i;

	for (int n=0; n<i; n++){
		cout << n+1 << ": ";
		cin >> s.vettore[n];
	}

    s.N = i;
}

void aggiungi_sequenza(Insieme &insieme, Sequenza &s) {
    if (insieme.num_seq == MAX_SEQ)
		throw 1;
    for (int i = 0 ; i < s.N ; i++)
		insieme.sequenze[insieme.num_seq].vettore[i] = s.vettore[i];
    insieme.sequenze[insieme.num_seq].N = s.N;
    insieme.num_seq++;
}

void stampa_insieme(const Insieme &ins) {
    for (int i = 0 ; i < ins.num_seq ; i++) {
		for (int j = 0 ; j < ins.sequenze[i].N ; j++)
			cout << ins.sequenze[i].vettore[j] << " ";
		cout << endl;
    }
    cout << endl;
}

void salva_insieme(const Insieme &ins) {
    ofstream f(FILENAME);
    f.write((char*)&ins, sizeof(ins));
	f.close();
}

void carica_insieme(Insieme &insieme) {
    ifstream f(FILENAME);
    f.read((char*)&insieme, sizeof(insieme));
	f.close();	
}

void elimina_ultima_Sequenza(Insieme &insieme){
	int l = insieme.sequenze[insieme.num_seq].N;
	cout << "l: " << l << endl;
	bool del = false;
	for (int i=0; i<l-1; i++){
		del = (insieme.sequenze[i].N < l);
		if (del){
			insieme.num_seq--;
			break;
		}
	}
}

bool presente(const Insieme &ins, int elem) {
    if (ins.num_seq == 1)
	return true;

    for (int i = 1 ; i < ins.num_seq ; i++) {
	int j;
	for (j = 0 ; j < ins.sequenze[i].N ; j++)
	    if (ins.sequenze[i].vettore[j] == elem)
		break;
	if (j == ins.sequenze[i].N)
	    return false;
    }
    return true;
}

bool aggiungi_sequenza_intersezione(Insieme &insieme) {
    if (insieme.num_seq == 0 || insieme.num_seq == MAX_SEQ)
	return false;
    int N_inters = 0;
    for (int i = 0 ; i < insieme.sequenze[0].N ; i++)
		if (presente(insieme, insieme.sequenze[0].vettore[i])) {
			insieme.sequenze[insieme.num_seq].vettore[N_inters] =
			insieme.sequenze[0].vettore[i];
			N_inters++;
		}
	if (N_inters > 0) {
		insieme.sequenze[insieme.num_seq].N = N_inters;
		insieme.num_seq++;
	} else
		return false;

    return true;
}

int main()
{
    Insieme insieme;
	Sequenza seq;


    char menu[] =
		"1. Aggiungi Sequenza all'insieme\n"
		"2. Stampa Insieme delle sequenze\n"
		"3. Salva Insieme delle sequenze\n"
		"4. Carica Insieme delle sequenze\n"
		"5. Elimina ultima sequenza\n"
		"6. Aggiungi Sequenza intersezione all'insieme\n"
		"7. Esci\n";

	bool running = true;
    while(running){
		cout << menu << endl;

		int scelta;
		cin >> scelta;
		switch(scelta) {
			case 1: // Aggiungi Sequenza all'insieme
				ask_seq(seq);
				try {
					aggiungi_sequenza(insieme, seq);
				} catch (int e){
					cout << "Insieme pieno" << endl;
				}
				break;
			case 2: // Stampa Insieme delle sequenze
				stampa_insieme(insieme);
				break;
			case 3: // Salva Insieme delle sequenze
				salva_insieme(insieme);
				break;
			case 4: // Carica Insieme delle sequenze
				carica_insieme(insieme);
				break;
			case 5: // Elimina ultima sequenza
				try {
					elimina_ultima_Sequenza(insieme);
				} catch (int e){
					cout << "Insieme privo di sequenze" << endl;
				}
				break;
			case 6: // Aggiungi sequenza intersezione all'insieme
				aggiungi_sequenza_intersezione(insieme);
				break;
			case 7: // Esci
				running = false;
				break;
			default:
				cout<<"Scelta errata"<<endl;
		}
	}
}
