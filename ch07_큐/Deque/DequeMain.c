#include <stdio.h>
#include "Deque.h"

int main(void) {

    Deque deque;
    DequeInit(&deque);

    AddFirst(&deque, 3);
    AddFirst(&deque, 2);
    AddFirst(&deque, 1);

    AddLast(&deque, 4);
    AddLast(&deque, 5);
    AddLast(&deque, 6);

    while(!DQIsEmpty(&deque))
        printf("%d ", RemoveFirst(&deque));

    printf("\n");

    AddFirst(&deque, 3);
    AddFirst(&deque, 2);
    AddFirst(&deque, 1);

    AddLast(&deque, 4);
    AddLast(&deque, 5);
    AddLast(&deque, 6);

    while(!DQIsEmpty(&deque))
        printf("%d ", RemoveLast(&deque));

    return 0;
}