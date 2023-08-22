#include <stdio.h>
#include "PriorityQueue.h"

int DataPriorityComp(char ch1, char ch2) {
    return ch2 - ch1;
}

int main(void) {

    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);

    PQEnqueue(&pq, 'D');
    PQEnqueue(&pq, 'A');
    PQEnqueue(&pq, 'B');
    PQEnqueue(&pq, 'C');
    PQEnqueue(&pq, 'F');

    printf("%c ", PQDequeue(&pq));
    printf("%c ", PQDequeue(&pq));

    printf("\n");

    PQEnqueue(&pq, 'A');
    PQEnqueue(&pq, 'B');
    PQEnqueue(&pq, 'A');
    PQEnqueue(&pq, 'B');

    while(!PQIsEmpty(&pq))
        printf("%c ", PQDequeue(&pq));

    return 0;
}