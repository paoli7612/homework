/*
  Scrivere un programma che stampi il contenuto di un vettore di
  interi definito ed inizializzato a tempo di scrittura del programma
  stesso e che contiene almeno un elemento di valore -1. In
  particolare lo stesso vettore va stampato due volte, utilizzando
  ciascuna volta una funzione diversa. Le due funzioni di stampa
  devono avere un solo parametro formale, non devono utilizzare
  variabili globali, e devono stampare gli elementi del vettore
  fermandosi non appena incontrano l'elemento di valore -1 (senza
  stamparlo).

  La prima funzione non deve utilizzare l'operazione di selezione con
  indice, mentre la seconda non deve utilizzare n� l'operazione di
  selezione con indice n� alcuna variabile locale.

 */

#include <iostream>

using namespace std;

void stampa_1(int v[])
{
	for (int i=0; *(v+i)!=-1; i++)
		cout << *(v+i) << " ";
	cout << endl;
}

void stampa_2(int v[])
{
	for (; *v!=-1; v++)
		cout << *v << " ";
	cout << endl;	
}

int main()
{
	int a[] = {1, 4, 3, -1};

	cout << "Stampa usando somma di un intero ad un indirizzo: ";
	stampa_1(a);
	
	cout << "Stampa usando incremento puntatore: ";
	stampa_2(a);
	
	return 0;
}


