#include <stdio.h>
#include "ArrayList.h"

int main(void){

    //ArrayList 생성 및 초기화
    List list;
    int data;
    ListInit(&list);

    //데이터 저장
    LInsert(&list, 13);
    LInsert(&list, 11);
    LInsert(&list, 17);
    LInsert(&list, 3);
    LInsert(&list, 20);

    //저장 된 데이터 개수 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));

    //저장 된 데이터 조회
    if(LFirst(&list, &data)) {
        printf("0번째 데이터 출력 : %d\n", data);

        //첫번째 데이터 조회 후 => curPoint=0;
        //연속으로 저장 된 데이터 모두 조회
        while(LNext(&list, &data))
            printf("%d번째 데이터 출력 : %d\n", LCursor(&list), data);
    }
    printf("\n");

    //데이터 삭제
    if(LFirst(&list, &data)) {
        
        if(data==17)
            LRemove(&list);

        while(LNext(&list, &data))
            if(data==17)
                LRemove(&list);
    }
    
    //삭제 후 남은 데이터 출력
    if(LFirst(&list, &data)) {
        printf("0번째 데이터 출력 : %d\n", data);

        //첫번째 데이터 조회 후 => curPoint=0;
        //연속으로 저장 된 데이터 모두 조회
        while(LNext(&list, &data))
            printf("%d번째 데이터 출력 : %d\n", LCursor(&list), data);
    }
    printf("\n");

    return 0;
}