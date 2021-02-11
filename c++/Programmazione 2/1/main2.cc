#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

#include "lista.h"

void stampa_lista(lista_t &lista)
{
  cout << "[ ";
  print(lista);
  cout << "] " << endl;
}

int main(int argc, char **argv)
{
  lista_t lista1 = NULL;
  lista_t lista2 = NULL;

  for (int i=0; i<10; i++)
  {
    insert(lista1, rand()%10);
    insert(lista2, rand()%10);
  }

  stampa_lista(lista1);
  stampa_lista(lista2);

  concat(lista1, lista2);


  stampa_lista(lista1);


  system("pause");

  return 0;
}
