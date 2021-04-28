
struct node_t {
    int value;
    node_t *left, *right;
};

typedef node_t *tree_t;

tree_t crea_albero(int level);
