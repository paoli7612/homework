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

// is pila vuota?
bool stack_empty(stack_t stack)
{
    return stack == NULL;
}

// inserisci nodo in cima
stack_t push(stack_t stack, node_t *node)
{
    node->next = stack;
    return stack;
}

// lettura valore in testa
int top(stack_t stack)
{
    return stack->value;
}

// lettura ed estrazione valore in testa
int pop(stack_t &stack)
{
    int value = stack->value;
    stack = stack->next;
    return value;
}

int main(int argc, char **argv)
{
    tail_t tail = new node_t{1, NULL};
    stack_t stack = new node_t{2, NULL};

    stampa(tail);
    stampa(stack);

    return 0;
}