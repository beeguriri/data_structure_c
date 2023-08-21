#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

void ListInit(List *plist) {
    
    plist -> head = (Node*)malloc(sizeof(Node));
    plist -> tail = (Node*)malloc(sizeof(Node));

    //최초 리스트 선언 시
    //head는 tail 가르키고
    //tail은 head 가르킴
    plist -> head -> prev = NULL;
    plist -> head -> next = plist -> tail;

    plist -> tail -> prev = plist -> head;
    plist -> tail -> next = NULL;

    plist -> numOfData = 0;
}

//새 노드 꼬리에 추가하기
void LInsert(List *plist, Data data) {

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;

    //tail의 앞에 newNode 추가
    newNode -> next = plist -> tail;
    newNode -> prev = plist -> tail -> prev;
    plist -> tail -> prev -> next = newNode;
    plist -> tail -> prev = newNode;

    (plist -> numOfData)++;

}

int LFirst(List *plist, Data *pdata) {

    //head가 tail 가르키고, tail이 head 가르키면 리스트 비었음
    if(plist -> head -> next == plist -> tail)
        return FALSE;

    plist -> cur = plist -> head -> next;
    *pdata = plist -> cur -> data;

    return TRUE;
}

int LNext(List *plist, Data *pdata) {
    
    if(plist -> cur -> next == plist -> tail)
        return FALSE;

    plist -> cur = plist -> cur -> next;
    *pdata = plist -> cur -> data;

    return TRUE;
}

Data LRemove(List *plist) {

    Node *rpos = plist -> cur;
    Data rdata = rpos -> data;

    //연결 바꿔주고
    plist -> cur -> prev -> next = plist -> cur -> next;
    plist -> cur -> next -> prev = plist -> cur -> prev;

    //현재위치 조정
    plist -> cur = plist -> cur -> prev;

    free(rpos);
    (plist -> numOfData)--;

    return rdata;
}

int LCount(List *plist) {
    return plist -> numOfData;
}