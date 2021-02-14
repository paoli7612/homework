#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

#include "grafo.h"

int main(int argc, char **argv)
{
  graph_t grafo;
  init(grafo, 10);

  connect(grafo, 2, 3);
  show(grafo);

  system("pause");

  return 0;
}
