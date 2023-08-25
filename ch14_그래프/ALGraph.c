#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "DLinkedList.h"

int WhoIsPrecede(int data1, int data2) {
    if(data1>data2)
        return 1;
    else
        return 0;
}

void GraphInit(ALGraph *pg, int nv) {
    int i;

    //정점의 수에 해당하는 길이의 리스트 배열 생성
    pg->adjList = (List*)malloc(sizeof(List)*nv);
    pg->numV = nv;  //정점의 수
    pg->numE = 0;   //간선의 수

    //정점의 개수만큼 리스트 초기화
    for(i=0; i<nv; i++) {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }
}

void GraphDestroy(ALGraph *pg) {
    if(pg->adjList != NULL)
        free(pg->adjList);
}

void AddEdge(ALGraph *pg, int fromV, int toV) {
    //양방향 연결 (무방향 그래프)
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

