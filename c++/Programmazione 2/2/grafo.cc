#include <iostream>

#include "grafo.h"

void add(list_t &list, const int n)
{
  if (list == NULL)
  {
    list = new node_t;
    list->value = n;
    list->next = NULL;
  }
  else
    add(list->next, n);
}

void init(graph_t &graph, const int N)
{
  graph.N = N;
  graph.vertices = new int[N];
  graph.adj = new list_t[N];

  for (int i=0; i<N; i++)
  {
    graph.vertices[i] = i;
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

void connect(graph_t &graph, const int a, const int b)
{
  add(graph.adj[a], b);
}
