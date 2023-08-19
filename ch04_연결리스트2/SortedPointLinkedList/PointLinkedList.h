#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#include "Point.h"

#define TRUE 1;
#define FALSE 0;

typedef Point *LData;

typedef struct _node
{
    LData data;
    struct _node *next;
} Node;

typedef struct _linkedList
{
    Node *head;     //더미노드 가르킴
    Node *cur;      //참조 및 삭제
    Node *before;   //삭제

    int numOfData;
    int (*comp)(LData d1, LData d2);    //정렬 기준
} LinkedList;

typedef LinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);
int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);
LData LRemove(List *plist);
int LCount(List *plist);

//int (*comp)(LData d1, LData d2)의 의미
//반환형은 int
//LData형 인자를 두개 전달 받는, "함수의 주소값"을 인자로 받음
void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));

#endif