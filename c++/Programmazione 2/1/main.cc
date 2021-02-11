#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

#include "lista.h"

void stampa_lista(list_t &lista)
{
  cout << "[ ";
  print(lista);
  cout << "] " << endl;
}

int main(int argc, char **argv)
{
  list_t lista = NULL;

  for (int i=0; i<10; i++)
    insert(lista, rand()%10);

  stampa_lista(lista);

  system("pause");

  return 0;
}
