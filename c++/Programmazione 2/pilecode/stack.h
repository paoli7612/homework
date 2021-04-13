// QUEUE

#include <iostream>

struct node_t {
    int value;
    node_t *next;
};    

struct stack_t {
    node_t *head;
};

void new_stack(stack_t &);
void print(const stack_t &);