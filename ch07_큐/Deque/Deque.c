#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque *pdq) {
    pdq->head = NULL;
    pdq->tail = NULL;
}
int DQIsEmpty(Deque *pdq) {
    if(pdq->head==NULL)
        return TRUE;
    return FALSE;
}

void AddFirst(Deque *pdq, Data data) {

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = pdq->head;

    if(DQIsEmpty(pdq))
        pdq->tail = newNode;
    else
        pdq->head->prev = newNode;

    pdq->head = newNode;
}

void AddLast(Deque *pdq, Data data) {

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = pdq->tail;
    newNode->next = NULL;

    if(DQIsEmpty(pdq))
        pdq->head = newNode;
    else
        pdq->tail->next = newNode;

    pdq->tail = newNode;

}

Data RemoveFirst(Deque *pdq) {

    if(DQIsEmpty(pdq)) {
        printf("큐가 비었습니다!!");
        exit(-1);
    }

    Node *delNode = pdq->head;
    Data delData = delNode->data;

    pdq->head = pdq->head->next;

    if(pdq->head == NULL) //비었음
        pdq->tail == NULL;
    else
        pdq->head->prev = NULL;
    
    free(delNode);

    return delData;

}

Data RemoveLast(Deque *pdq) {

    if(DQIsEmpty(pdq)) {
        printf("큐가 비었습니다!!");
        exit(-1);
    }

    Node *delNode = pdq->tail;
    Data delData = delNode->data;

    pdq->tail = pdq->tail->prev;

    if(pdq->tail == NULL)
        pdq->head = NULL;
    else
        pdq->tail->next = NULL;

    free(delNode);

    return delData;
}

Data PeekFirst(Deque *pdq) {

    if(DQIsEmpty(pdq)) {
        printf("큐가 비었습니다!!");
        exit(-1);
    }

    return pdq->head->data;
}

Data PeekLast(Deque *pdq) {

    if(DQIsEmpty(pdq)) {
        printf("큐가 비었습니다!!");
        exit(-1);
    }

    return pdq->tail->data;
}