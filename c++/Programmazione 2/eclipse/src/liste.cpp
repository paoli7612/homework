/*
 * liste.cpp
 *
 *  Created on: 10 apr 2021
 *      Author: paoli7612
 */


#include <iostream>
#include "../include/liste.h"

using namespace std;

void stampa_lista(list_t lista)
{
	while (lista != NULL)
		cout << lista->value << " ";
	cout << endl;
}

list_t nuovo_nodo(int value)
{
	node_t *nodo = new node_t;
	nodo->value = value;
	nodo->next = NULL;
	return nodo;
}

list_t aggiungi_testa(list_t lista, node_t* nodo)
{
	nodo->next = lista;
	return nodo;
}

list_t aggiungi_testa(list_t lista, int value)
{
	aggiungi_testa(lista, nuovo_nodo(value));
}

void cancella_lista(list_t lista)
{
	if (lista == NULL)
		return;

	cancella_lista(lista->next);
	delete lista;
}

list_t cancella_nodo(list_t lista, node_t *nodo)
{
	if (lista == nodo)
	{
		list_t nuova = nodo->next;
		delete nodo;
		return nuova;
	}

	while (lista != NULL && lista->next != nodo)
		lista = lista->next;

	if (lista == NULL)
		return lista;

	lista->next = nodo->next;
	delete nodo;

}

list_t crea_lista(int n)
{
	list_t lista = NULL;
	while (n--)
		lista = aggiungi_testa(lista, n);
	return lista;

}
