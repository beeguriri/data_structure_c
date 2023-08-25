#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "ALGraphBFS.h"
#include "DLinkedList.h"
#include "CircularQueue.h"

int WhoIsPrecede(int data1, int data2) {
    if(data1>data2)
        return 1;
    else
        return 0;
}

void GraphInit(ALGraph *pg, int nv) {

    int i;

    pg->adjList = (List*)malloc(sizeof(List)*nv);
    pg->visitInfo = (int*)malloc(sizeof(int)*nv);
    pg->numV = nv;
    pg->numE = 0;

    //정점의 개수만큼 리스트 초기화
    for(i=0; i<nv; i++) {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }

    //방문 배열 초기화
    memset(pg->visitInfo, 0, sizeof(int)*nv);
}

void GraphDestroy(ALGraph *pg) {
    if(pg->adjList != NULL)
        free(pg->adjList);

    if(pg->visitInfo != NULL)
        free(pg->visitInfo);
}

void AddEdge(ALGraph *pg, int fromV, int toV) {

    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);

    (pg->numE)++;
}

void showGraphEdgeInfo(ALGraph *pg) {

    int i;
    int vx;

    for(i=0; i<pg->numV; i++) {
        printf("%c와 연결 된 정점: ", i+65);

        if(LFirst(&(pg->adjList[i]), &vx)) {
            printf("%c ", vx+65);

            while(LNext(&(pg->adjList[i]), &vx))
                printf("%c ", vx+65);
        }
        printf("\n");
    }
}

int VisitVertex(ALGraph *pg, int visitV) {
    if(pg->visitInfo[visitV] == 0) {
        pg->visitInfo[visitV] = 1;  //방문 체크
        printf("%c ", visitV+65);   //방문한 정점
        return TRUE;
    }
    return FALSE;
}

void BFSShowGraphVertexInfo(ALGraph *pg, int startV) {

    Queue queue;
    int visitV = startV;
    int nextV;

    QueueInit(&queue);
    VisitVertex(pg, visitV);

    while(LFirst(&(pg->adjList[visitV]), &nextV)) {

        if(VisitVertex(pg, nextV))
            Enqueue(&queue, nextV);
        
        //현재 정점에 연결 된 방문 가능한 리스트 모두 방문
        while(LNext(&(pg->adjList[visitV]), &nextV))
            if(VisitVertex(pg, nextV))
                Enqueue(&queue, nextV);
        
        if(QIsEmpty(&queue))
            break;
        else
            //방문 가능한 다음 정점부터 다시 순회
            visitV = Dequeue(&queue);
    }

    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);

}