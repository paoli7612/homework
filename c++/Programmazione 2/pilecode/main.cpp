#include <iostream>

#include "queue.h"

using namespace std;

int main(int argc, char **argv)
{
    queue_t queue;
    new_queue(queue);
    
    print(queue);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    print(queue);
    dequeue(queue);
    print(queue);
    dequeue(queue);
    print(queue);


    return 0;
}