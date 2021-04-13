#include <iostream>

#include "queue.h"

using namespace std;

void new_queue(queue_t &queue)
{
    queue.head = NULL;
    queue.tail = NULL;
}

void print(const queue_t &queue)
{
    node_t* pointer = queue.head;
    while (pointer != NULL)
    {
        cout << pointer->value << " ";
        pointer = pointer->next;
    }
    cout << endl;
}

void enqueue(queue_t &queue, node_t *node)
{
    if (queue.head == NULL) // empty queue 
    {
        queue.head = node;
    }
    else 
    {
        queue.tail->next = node;
    }
    queue.tail = node;
}

void enqueue(queue_t &queue, int value)
{
    enqueue(queue, new node_t {value, NULL});
}

void dequeue(queue_t &queue)
{
    node_t* new_head = queue.head->next;
    delete queue.head;
    queue.head = new_head;
}