struct node_t {
  int value;
  node_t *next;
};

typedef node_t *lista_t;

void print(lista_t &);
void insert(lista_t &, int);
void concat(lista_t &, lista_t &);
