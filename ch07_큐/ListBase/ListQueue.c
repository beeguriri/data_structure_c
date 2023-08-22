#include <stdio.h>
#include <stdlib.h>
#include "ListQueue.h"

void QueueInit(Queue *pq) {
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue *pq) {
    if(pq->front == NULL)
        return TRUE;
    return FALSE;
}

void Enqueue(Queue *pq, Data data) {

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;

    if(QIsEmpty(pq)) 
        pq->front = newNode;
    else
        pq->rear->next = newNode;

    pq->rear = newNode;

}

Data Dequeue(Queue *pq) {

    if(QIsEmpty(pq)) {
        printf("큐가 비었습니다!!");
        exit(-1);
    }

    Node *delNode;
    Data rdata;

    delNode = pq -> front;
    rdata = delNode -> data;
    pq -> front = pq -> front -> next;

    free(delNode);

    return rdata;
}

Data QPeek(Queue *pq) {

    if(QIsEmpty(pq)) {
        printf("큐가 비었습니다!!");
        exit(-1);
    }

    return pq -> front -> data;

}