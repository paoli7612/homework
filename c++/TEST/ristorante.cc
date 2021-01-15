#include <iostream>

using namespace std;

// | ? ? ? ? ... ? |
// | 0 1 2 3 ... N | 
//   inizio = 0
//   quanti = 0

// add 3
// | 3 ? ? ? ... ? |
// | 0 1 2 3 ... N | 
//   inizio = 0
//   quanti = 1

// add 6
// | 3 6 ? ? ... ? |
// | 0 1 2 3 ... N | 
//   inizio = 0
//   quanti = 2

// rimuovi il primo
// | ? 6 ? ? ... ? |
// | 0 1 2 3 ... N | 
//   inizio = 1
//   quanti = 1

struct coda_t {
	int* numeri;
	int N; // max numeri
	int inizio, quanti;
};

int main(){
	
	
	return 0;
}
