#include <stdio.h>
#include <stdlib.h>
#include "PointLinkedList.h"

int WhoIsPrecede(Point *d1, Point *d2) {
    
    //x좌표값 기준 오름차순
    //x가 같으면 y좌표 기준 오름차순
    if(d1->xpos < d2->xpos)
        return 0;
    else if(d1->xpos == d2->xpos) {
        if(d1->ypos < d2->ypos)
            return 0;
        else
            return 1;
    }
    else
        return 1;
}

int main(void){

    //리스트의 생성 및 초기화
    List list;
    Point comp;
    Point *pPoint;
    ListInit(&list);
    SetSortRule(&list, WhoIsPrecede);

    //데이터 저장
    pPoint = (Point*)malloc(sizeof(Point));
    SetPointPos(pPoint, 1, 2);
    LInsert(&list, pPoint);

    pPoint = (Point*)malloc(sizeof(Point));
    SetPointPos(pPoint, 3, 3);
    LInsert(&list, pPoint);

    pPoint = (Point*)malloc(sizeof(Point));
    SetPointPos(pPoint, 1, 4);
    LInsert(&list, pPoint);

    pPoint = (Point*)malloc(sizeof(Point));
    SetPointPos(pPoint, 2, 2);
    LInsert(&list, pPoint);

    //데이터 출력
    printf("현재 저장 된 데이터의 수 : %d개\n", LCount(&list));

    if(LFirst(&list, &pPoint)) {

        ShowPointPos(pPoint);

        while(LNext(&list, &pPoint))
            ShowPointPos(pPoint);
        
    }
    printf("\n\n");

    //2,2 삭제
    comp.xpos = 2;
    comp.ypos = 2;
    
    if(LFirst(&list, &pPoint)) {

        if(PointComp(pPoint, &comp)==0){
            pPoint = LRemove(&list);
            free(pPoint);
        }

        while(LNext(&list, &pPoint)){
            if(PointComp(pPoint, &comp)==0){
                pPoint = LRemove(&list);
                free(pPoint);
            }
        }
        
    }

    //삭제 후 남은 데이터 출력
    printf("현재 저장 된 데이터의 수 : %d개\n", LCount(&list));

    if(LFirst(&list, &pPoint)) {

        ShowPointPos(pPoint);

        while(LNext(&list, &pPoint))
            ShowPointPos(pPoint);
        
    }
    printf("\n\n");

    return 0;
}