#include <stdio.h>
#include "DBLinkedList.h"

int main(void) {

    List list;
    int data;
    ListInit(&list);

    LInsert(&list, 1);  LInsert(&list, 2);
    LInsert(&list, 3);  LInsert(&list, 4);
    LInsert(&list, 5);  LInsert(&list, 6);
    LInsert(&list, 7);  LInsert(&list, 8);

    //데이터 앞에서 부터 출력
    if(LFirst(&list, &data)) {

        printf("데이터 앞에서 부터 출력: ");
        printf("%d ", data);

        while(LNext(&list, &data))
            printf("%d ", data);

        printf("\n");

        printf("데이터 뒤에서 부터 출력: ");
        printf("%d ", data);
        while(LPrev(&list, &data))
            printf("%d ", data);

    }
    printf("\n");

}