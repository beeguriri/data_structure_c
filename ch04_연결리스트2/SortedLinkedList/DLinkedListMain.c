#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2) {
    if(d1<d2)
        return 0;
    else
        return 1;
}

int main(void){

    //리스트의 생성 및 초기화
    List list;
    int data;
    ListInit(&list);
    SetSortRule(&list, WhoIsPrecede);

    //데이터 저장
    LInsert(&list, 11); LInsert(&list, 22);
    LInsert(&list, 33); LInsert(&list, 22);
    LInsert(&list, 11); LInsert(&list, 33);

    //데이터 출력
    printf("현재 저장 된 데이터의 수 : %d개\n", LCount(&list));

    if(LFirst(&list, &data)) {

        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
        
    }
    printf("\n\n");

    //숫자22 모두 삭제
    if(LFirst(&list, &data)) {

        if(data==22)
            LRemove(&list);

        while(LNext(&list, &data))
            if(data==22)
                LRemove(&list);
        
    }

    //삭제 후 남은 데이터 출력
        printf("현재 저장 된 데이터의 수 : %d개\n", LCount(&list));

    if(LFirst(&list, &data)) {

        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);
        
    }
    printf("\n\n");

    return 0;
}