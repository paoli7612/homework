/*
Scrivere un programma in cui:
		sia definita (a tempo di scrittura del programma stesso)
	una lista formata da due elementi, contenenti i valori 3
	e 7
		si stampi il contenuto della lista mediante la funzione
	stampalista
*/

#include <iostream>

using namespace std;

struct node_t {
	int v;
	node_t* next;
};

void stampa(node_t* head){
	cout << head->v << endl;
	if (head->next != NULL)
		stampa(head->next);
}

int main(){
	node_t* head = new node_t;
	head->v = 3;
	head->next = new node_t;
	head->next->next = NULL;
	head->next->v = 7;
	
	stampa(head);
	
	
}
