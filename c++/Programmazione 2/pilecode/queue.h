// QUEUE

#include <iostream>

struct node_t {
    int value;
    node_t *next;
};    

struct queue_t {
    node_t *head;
    node_t *tail;
};

void new_queue(queue_t &queue);
void print(const queue_t &);

void enqueue(queue_t &, node_t *);
void enqueue(queue_t &queue, int value);

void dequeue(queue_t &);