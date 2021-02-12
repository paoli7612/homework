struct node_t {
  int value;
  node_t *next;
};

typedef node_t *list_t;

struct graph_t {
  int *vertices;
  list_t *adj;
};

void init(graph_t &, const int);
