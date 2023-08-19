#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

//초기화
void ListInit(List *plist){
    //head == dummy node
    plist -> head = (Node*)malloc(sizeof(Node));
    plist -> head -> next = NULL;

    //정렬기준, data 개수 초기화
    plist -> comp = NULL;
    plist -> numOfData = 0;
}

//리스트의 처음(dummy 뒤)에 데이터 추가
void FInsert(List *plist, LData data) {

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;

    newNode -> next = plist -> head -> next;
    plist -> head -> next = newNode;

    (plist -> numOfData)++;
}

//리스트 정렬 여부 확인 해서 데이터 추가
void SInsert(List *plist, LData data) {

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;

    Node *pred = plist -> head; //더미노드 가르킴

    //새 노드가 들어 갈 위치 확인
    //comp => d1<d2 ? 0 : 1
    //while문 => d1>=d2일때 d1을 d2 다음에에 넣기 위함
    while(pred->next != NULL && plist -> comp(data, pred->next->data)!=0)
        pred = pred -> next;
    
    //노드 연결 바꿔줌
    newNode -> next = pred -> next;
    pred -> next = newNode;

    (plist->numOfData)++;

}

void LInsert(List *plist, LData data){

    if(plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}

//리스트의 첫번째 데이터 확인
int LFirst(List *plist, LData *pdata){

    if(plist -> head -> next == NULL)
        return FALSE;
    
    plist -> before = plist -> head;
    plist -> cur = plist -> head -> next;
    *pdata = plist -> cur -> data;

    return TRUE;
}

//리스트의 첫번째 이후 데이터 탐색
int LNext(List *plist, LData *pdata){

    if(plist -> cur -> next == NULL)
        return FALSE;
    
    plist -> before = plist -> cur;
    plist -> cur = plist -> cur -> next;
    *pdata = plist -> cur -> data;

    return TRUE;
}

//cur 위치의 데이터 삭제
LData LRemove(List *plist){
    
    Node *rpos = plist -> cur;
    LData rdata = rpos -> data;

    //연결을 바꿔주고
    //cur와 before가 가르키는 노드가 같아짐
    plist -> before -> next = plist -> cur -> next;
    plist -> cur = plist -> before;

    //삭제
    free(rpos);
    (plist -> numOfData)--;
    
    return rdata;
}

int LCount(List *plist){
    return plist -> numOfData;
}

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2)){
    plist -> comp = comp;
    
    //정렬 기준은 main함수에서 정의한다
}