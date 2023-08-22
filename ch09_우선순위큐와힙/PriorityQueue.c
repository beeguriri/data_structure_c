#include "PriorityQueue.h"
#include "Heap.h"

void PQueueInit(PQueue *ppq, PriorityComp pc) {
    HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue *ppq){
    return IsEmpty(ppq);
}

void PQEnqueue(PQueue *ppq, PQData data) {
    Insert(ppq, data);
}

PQData PQDequeue(PQueue *ppq) {
    return Delete(ppq);
}