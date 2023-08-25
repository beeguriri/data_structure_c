#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack *pstack) {
    pstack -> topIndex = -1;
}

int IsEmpty(Stack *pstack) {
    if(pstack -> topIndex == -1)
        return TRUE;
    return FALSE;
}

int IsFull(Stack *pstack) {
    if(pstack -> topIndex == STACK_LEN-1)
        return TRUE;
    return FALSE;
}

void Push(Stack *pstack, Data data){

    if(IsFull(pstack)) {
        printf("스택이 가득 찼습니다!!");
        exit(-1);
    }

    pstack -> stackArr[++(pstack->topIndex)] = data;
}

Data Pop(Stack *pstack) {

    if(IsEmpty(pstack)) {
        printf("스택이 비었습니다!!");
        exit(-1);
    }

    return pstack -> stackArr[(pstack->topIndex)--];
    
}

Data Peek(Stack *pstack) {

    if(IsEmpty(pstack)) {
        printf("스택이 비었습니다!!");
        exit(-1);
    }

    return pstack -> stackArr[pstack -> topIndex];
}
