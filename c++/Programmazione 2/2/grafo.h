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
