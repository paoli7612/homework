#include <iostream>

#include "grafo.h"

void init(graph_t &graph, const int N)
{
  graph.vertices = new int[N];
  graph.adj = new list_t[N];
}
