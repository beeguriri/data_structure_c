#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "ALGraphDFS.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

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
    
    //정점의 수에 해당하는 길이의 방문 배열 생성
    pg->visitInfo = (int*)malloc(sizeof(int)*nv);

    pg->numV = nv;  //정점의 수
    pg->numE = 0;   //간선의 수

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

void DFSShowGraphVertexInfo(ALGraph *pg, int startV) {

    Stack stack;
    int visitV = startV;
    int nextV;

    //최초 방문점 스택에 넣고, 방문 정점 체크 해줌
    StackInit(&stack);
    VisitVertex(pg, visitV);
    Push(&stack, visitV);

    //현재 방문 정점에 연결 된 리스트의 첫번째 값을 다음정점으로 함
    while(LFirst(&(pg->adjList[visitV]), &nextV)) {
        
        int visitFlag = FALSE;

        //방문에 성공하면 stack에 push 후 
        //최초 while문에서 다음정점의 리스트 탐색
        if(VisitVertex(pg, nextV)){
            Push(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE;
        } else {
            //현재 방문 정점에 연결 된 리스트의 다음 인덱스값을 방문 정점으로 함
            while(LNext(&(pg->adjList[visitV]), &nextV)) {
                if(VisitVertex(pg, nextV)) {
                    Push(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }

        //이미 방문한 정점일 경우
        //길을 되돌아가야함 (visitV 재설정)
        if(!visitFlag) {
            if(IsEmpty(&stack))
                break;
            else
                visitV = Pop(&stack);
        }
    }

    //방문 배열 초기화
    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}