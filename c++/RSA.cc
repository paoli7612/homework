// RSA

#include <iostream>
#include <math.h>

using namespace std;

struct chiave_t {
	int e, d, r;
};

 

int potenza(int n, int e, int r){
	if (e == 0)
       return 1;
    return (n * potenza(n,e-1, r)) % r ;
}

int cifra(chiave_t &c, int n){
	return potenza(n, c.e, c.r);
}

int decifra(chiave_t &c, int n){
	return potenza(n, c.d, c.r);
}

chiave_t nuova(int e, int d, int r){
	chiave_t c;
	c.e = e;
	c.d = d;
	c.r = r;
	return c;
}

int main(){
	
	int i[] = {5, 4, 2, 3};
	
	chiave_t chiave = nuova(5, 173, 323);
	//STAMA
	for (int a=0; a<4; a++)
		cout << i[a] << " ";cout << endl;
	// CIFRA
	for (int a=0; a<4; a++)
		i[a] = cifra(chiave, i[a]);
	///STAMPA
	for (int a=0; a<4; a++)
		cout << i[a] << " ";cout << endl;
	//DECIFRA
	for (int a=0; a<4; a++)
		i[a] = decifra(chiave, i[a]);
	//STAMPA
	for (int a=0; a<4; a++)
		cout << i[a] << " ";cout << endl;
	
	return 0;
}



