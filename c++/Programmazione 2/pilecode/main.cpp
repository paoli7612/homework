#include <iostream>

using namespace std;

struct node_t {
    int value;
    node_t *next;
};

typedef node_t* stack_t;
typedef node_t* tail_t;

void stampa(node_t *node)
{
    if (node == NULL)
    {
        cout << endl;
        return;
    }
    cout << node->value << " ";
    stampa(node->next);
}



int main(int argc, char **argv)
{
    tail_t tail = new node_t{1, NULL};
    stack_t stack = new node_t{2, NULL};

    stampa(tail);
    stampa(stack);

    return 0;
}