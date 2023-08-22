#include <stdio.h>
#include "CircularQueue.h"

int main(void) {

    Queue queue;
    QueueInit(&queue);

    Enqueue(&queue, 1);
    Enqueue(&queue, 2);
    Enqueue(&queue, 3);
    Enqueue(&queue, 4);
    
    //Enqueue(&queue, 5); //큐가 가득참
    
    while(!QIsEmpty(&queue)) {
        printf("peek : %d  ", QPeek(&queue));
        printf("deque : %d", Dequeue(&queue));
        printf("\n");
    }

    return 0;
}