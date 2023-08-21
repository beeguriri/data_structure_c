#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

//초기화
void ListInit(List *plist){
    plist -> tail = NULL;
    plist -> cur = NULL;
    plist -> before = NULL;
    plist -> numOfData = 0;
}

//꼬리에 노드 추가
//꼬리를 계속 갱신
void LInsert(List *plist, Data data){

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;

    if(plist -> tail == NULL) {
        plist -> tail = newNode;
        newNode -> next = newNode;
    } else {
        newNode -> next = plist -> tail -> next;
        plist -> tail -> next = newNode;
        plist -> tail = newNode;
    }

    (plist -> numOfData)++;

}       

//헤드에 노드 추가
//꼬리가 움직이지 않음
void LInsertFront(List *plist, Data data){

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;

    if(plist -> tail == NULL) {
        plist -> tail = newNode;
        newNode -> next = newNode;
    } else {
        newNode -> next = plist -> tail -> next;
        plist -> tail -> next = newNode;
    }

    (plist -> numOfData)++;

}

int LFirst(List *plist, Data *pdata){

    if(plist -> tail == NULL)
        return FALSE;

    plist -> before = plist -> tail; //befor는 꼬리
    plist -> cur = plist -> tail -> next; //cur는 헤드

    *pdata = plist -> cur -> data;
    
    return TRUE;
    
}

int LNext(List *plist, Data *pdata){

    //끝을 검사하는 코드가 존재하지 않으므로 무한반복
    // if(plist -> cur -> next == NULL)
    //     return FALSE;

    plist -> before = plist -> cur;
    plist -> cur = plist -> cur -> next;

    *pdata = plist -> cur -> data;
    
    return TRUE;
}

Data LRemove(List *plist){

    Node *rpos = plist -> cur;
    Data rdata = rpos -> data;

    //삭제하려는게 꼬리 노드일때
    if(rpos == plist -> tail) {
        //노드가 하나만 있으면
        if(plist -> tail == plist -> tail -> next)
            plist -> tail == NULL;

        //노드가 여러개 남아있으면
        else
            //before를 꼬리노드로 지정
            plist -> tail = plist -> before;
    }

    //before의 next를 cur의 next와 연결
    //cur는 한칸 전인 before 위치로 이동
    plist -> before -> next = plist -> cur -> next;
    plist -> cur = plist -> before;

    free(rpos);
    (plist -> numOfData)--;

    return rdata;

}

int LCount(List *plist){
    return plist -> numOfData;
}