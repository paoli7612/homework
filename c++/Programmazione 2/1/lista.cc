#include <iostream>

#include "lista.h"

void print(list_t &list)
{
  if (list == NULL)
    return;

  std::cout << list->value << " ";
  print(list->next);
}

void insert(list_t &list, const int value)
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

void concat(list_t &a, list_t &b)
{
  if (a == NULL)
    a = b;
  else
    concat(a->next, b);
}
