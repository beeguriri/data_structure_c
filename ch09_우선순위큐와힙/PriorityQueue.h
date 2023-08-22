#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "Heap.h"

typedef Heap PQueue;
typedef Data PQData;

void PQueueInit(PQueue *ppq, PriorityComp pc);
int PQIsEmpty(PQueue *ppq);

void PQEnqueue(PQueue *ppq, PQData data);
PQData PQDequeue(PQueue *ppq);

#endif