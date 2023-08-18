#include <stdio.h>
#include <stdlib.h>
#include "PointArrayList.h"
#include "Point.h"

int main(void){

    //ArrayList 생성 및 초기화
    List list;
    Point compPos;
    Point *ppos; //저장된 데이터
    ListInit(&list);

    //데이터 저장
    //malloc : 동적으로 메모리 할당
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);

    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);
    

    //저장 된 데이터 개수 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));

    //저장 된 데이터 조회
    if(LFirst(&list, &ppos)) {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos))
            ShowPointPos(ppos);
    }
    printf("\n");

    // x==2 인 데이터 삭제
    compPos.xpos = 2;
    compPos.ypos = 0;
    
    if(LFirst(&list, &ppos)) {
        
        if(PointComp(ppos, &compPos)==1) {
            ppos = LRemove(&list);
            free(ppos);
        }

        while(LNext(&list, &ppos)) {
            if(PointComp(ppos, &compPos)==1) {
                ppos = LRemove(&list);
                free(ppos);
            }
        }
    }
    
    //삭제 후 남은 데이터 출력
    if(LFirst(&list, &ppos)) {
        ShowPointPos(ppos);

        while(LNext(&list, &ppos))
            ShowPointPos(ppos);
    }
    printf("\n");

    return 0;
}