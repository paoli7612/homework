#include <iostream>

#include "lista.h"

void print(lista_t &lista)
{
  if (lista == NULL)
    return;

  std::cout << lista->value << " ";
  print(lista->next);
}

void insert(lista_t &list, const int value)
{
  if (list == NULL)
  {
    list = new node_t;
    list->value = value;
    list->next = NULL;
  }
  else
    insert(list->next, value);
}

void concat(lista_t &a, list_t &b)
{
  if (a == NULL)
    a = b;
  else
    concat(a->next, b);
}
