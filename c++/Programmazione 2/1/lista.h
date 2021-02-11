struct node_t {
  int value;
  node_t *next;
};

typedef node_t *list_t;

void print(list_t &);
void insert(list_t &, int);
void concat(list_t &, list_t &);
