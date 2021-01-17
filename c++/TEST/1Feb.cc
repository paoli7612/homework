/*10. (6 pt) Scrivere una funzione che prende in ingresso una stringa e ritorna una nuova stringa in cui
ogni sequenza di più di due caratteri uguali contenuta nella stringa in ingresso è stata sostituita da due
sole occorrenze di tale carattere. Ad esempio, presa in ingresso la stringa "aabhhhhagggf", la funzione
deve ritornare la stringa "aabhhaggf". L'array di caratteri in cui è memorizzata la stringa ritornata deve
avere le dimensioni minime necessarie per contenere tale stringa.*/

#include <iostream>

using namespace std;

//		0  1  2  3  4  5  6  7  8  9  10 11
//		a  a  b  h  h  h  h  a  g  g  g  f
//		a  a  b  h  h  a  g  g  f	
//

char* fun(const char stringa[], const int &dim){
	char* result = new char[dim];
	int index = 0;
	
	int i = 0;
	while (i<dim){
		result[index++] = stringa[i++];
		while(stringa[i] == stringa[i+2])
			i++;
	}
	
	char* final = new char[index+1];
	for (int i=0; i<index; i++)
		final[i] = result[i];
	final[index] = '\0';
	delete [] result;

	return final;
}


int main(){
	
	const char* stringa = "aabhhhhagggf";	
	char* result = fun(stringa, 12);
	cout << result;
	
	return 0;
}
