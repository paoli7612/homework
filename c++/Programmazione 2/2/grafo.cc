#include <iostream>

#include "grafo.h"

void init(graph_t &graph, const int N)
{
  graph.N = N;
  graph.vertices = new int[N];
  graph.adj = new list_t[N];

  for (int i=0; i<N; i++)
  {
    graph.vertices[i] = 1+i;
    graph.adj[i] = NULL;
  }
}

void show(list_t list)
{
  if (list == NULL)
    return;
  std::cout << list->value;
  show(list->next);
}

void show(const graph_t &graph)
{
  for (int i=0; i<graph.N; i++)
  {
    std::cout << graph.vertices[i] << ": [";
    show(graph.adj[i]);
    std::cout << "]" << std::endl;
  }
}
