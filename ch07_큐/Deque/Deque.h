#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1;
#define FALSE 0;

typedef int Data;

typedef struct _node {
    Data data;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct _dlDeque {
    Node *head;
    Node *tail;
} DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque *pdq);
int DQIsEmpty(Deque *pdq);

void AddFirst(Deque *pdq, Data data);
void AddLast(Deque *pdq, Data data);

Data RemoveFirst(Deque *pdq);
Data RemoveLast(Deque *pdq);

Data PeekFirst(Deque *pdq);
Data PeekLast(Deque *pdq);

#endif