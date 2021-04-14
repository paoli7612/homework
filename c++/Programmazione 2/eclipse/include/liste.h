/*
 * liste.h
 *
 *  Created on: 10 apr 2021
 *      Author: paoli7612
 */

#ifndef INCLUDE_LISTE_H_
#define INCLUDE_LISTE_H_

struct node_t {
	int value;
	node_t *next;
};

typedef node_t *list_t;

void stampa_lista(list_t);

list_t nuovo_nodo(int);
list_t aggiungi_testa(list_t, node_t*);
list_t aggiungi_testa(list_t, int);
list_t aggiungi_coda(list_t, node_t*);
list_t aggiungi_coda(list_t, int);

void cancella_lista(list_t);

list_t crea_lista(int);

#endif /* INCLUDE_LISTE_H_ */
