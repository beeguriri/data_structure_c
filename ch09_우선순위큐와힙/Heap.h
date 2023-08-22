#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char Data;
typedef int PriorityComp(Data d1, Data d2);

typedef struct _heap {
    PriorityComp *comp;
    int numOfData;
    Data heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph, PriorityComp pc);
int IsEmpty(Heap *ph);

void Insert(Heap *ph, Data data);
Data Delete(Heap *ph);

#endif