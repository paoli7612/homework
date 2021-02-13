# 1 Lista
```cpp
struct node_t {
  int value;
  node_t *next;
};

typedef node_t *list_t;

void print(list_t &);
void insert(list_t &, int);
void concat(list_t &, list_t &);
```


# 2 Grafo
```cpp
struct node_t {
  int value;
  node_t *next;
};

typedef node_t *list_t;

struct graph_t {
  int *vertices;
  list_t *adj;
  int N;
};

void init(graph_t &, const int);
void show(const graph_t &);
```
