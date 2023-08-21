#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack *pstack) {
    pstack -> head = NULL;
}

int IsEmpty(Stack *pstack) {
    if(pstack -> head == NULL)
        return TRUE;

    return FALSE;
}

void Push(Stack *pstack, Data data) {

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = pstack -> head;

    pstack -> head = newNode;

}

Data Pop(Stack *pstack) {

    if(IsEmpty(pstack)) {
        printf("스택이 비었습니다!!");
        exit(-1);
    }

    //헤드의 위치를 바꾸고 기존헤드는 메모리 반납
    Node *rNode;
    Data rData;

    rNode = pstack -> head;
    rData = pstack -> head -> data;

    pstack -> head = pstack -> head -> next;
    free(rNode);

    return rData;

}

Data Peek(Stack *pstack) {

    if(IsEmpty(pstack)) {
        printf("스택이 비었습니다!!");
        exit(-1);
    }

    return pstack -> head -> data;
}