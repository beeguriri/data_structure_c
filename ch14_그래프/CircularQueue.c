#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue *pq) {
    pq -> front = 0;
    pq -> rear = 0;
}

//Front와 Rear가 같은 위치를 가르키면 empty
int QIsEmpty(Queue *pq) {

    if(pq -> front == pq -> rear)
        return TRUE;

    return FALSE;
}

//Front가 Rear의 하나 앞에 있으면 full
int QIsFull(Queue *pq) {

    if(pq -> front == (pq -> rear + 1) % QUE_LEN)
        return TRUE;

    return FALSE;
}

void Enqueue(Queue *pq, Data data) {

    if(QIsFull(pq)) {
        printf("큐가 가득 찼습니다!!");
        exit(-1);
    }
    
    pq -> rear = (pq -> rear + 1) % QUE_LEN;
    pq -> queArr[pq->rear] = data;

}

Data Dequeue(Queue *pq) {

    if(QIsEmpty(pq)) {
        printf("큐가 비었습니다!!");
        exit(-1);
    }

    pq -> front = (pq -> front + 1) % QUE_LEN;

    return pq -> queArr [pq->front];
}

Data QPeek(Queue *pq) {

    if(QIsEmpty(pq)) {
        printf("큐가 비었습니다!!");
        exit(-1);
    }

    Data peekData = pq -> queArr[(pq -> front + 1) % QUE_LEN];

    return peekData;
}
