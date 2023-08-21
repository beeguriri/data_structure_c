#include <stdio.h>
#include "CLinkedList.h"

int main(void) {

    List list;
    int data, i, nodeNum;
    ListInit(&list);

    //데이터 삽입
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);
    LInsert(&list, 6);
    LInsert(&list, 7);
    LInsert(&list, 8);
    LInsertFront(&list, 10);
    LInsertFront(&list, 9);

    //데이터 출력
    if(LFirst(&list, &data)) {
        printf("%d ", data);

        //종료조건이 없어 횟수 제한 해줘야함
        for(i=1; i<LCount(&list); i++)
            if(LNext(&list, &data))
                printf("%d ", data);
    }
    printf("\n\n");

    //2의 배수 삭제
    nodeNum = LCount(&list);
    if(nodeNum != 0) {
        if(LFirst(&list, &data)) {
            if(data%2==0)
                LRemove(&list);

            for(i=1; i<nodeNum; i++)
                if(LNext(&list, &data))
                    if(data%2==0)
                        LRemove(&list);
        }
    }

    //데이터 출력
    if(LFirst(&list, &data)) {
        printf("%d ", data);

        //종료조건이 없어 횟수 제한 해줘야함
        for(i=1; i<LCount(&list); i++)
            if(LNext(&list, &data))
                printf("%d ", data);
    }
    printf("\n\n");
}