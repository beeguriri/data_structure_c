#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE 1;
#define FALSE 0;

typedef int Data;

typedef struct _node {
    Data data;
    struct _node *prev;
    struct _node *next;
} Node;

typedef struct _DLinkedList {
  Node *head;
  Node *cur;
  int numOfData;  
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, Data data);

int LFirst(List *plist, Data *data);
int LNext(List *plist, Data *pdata);
int LPrev(List *plist, Data *pdata);

// Data LRemove(List *plist);
int LCount(List *plist);

#endif