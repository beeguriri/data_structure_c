#include <stdio.h>
#include "ArrayList.h"

//문제03-1
//리스트를 생성 및 초기화 한 다음 1~9까지 저장
//저장된 값을 순차적으로 참조하여 합을 출력
//리스트에 저장된 값들 중 2의 배수와 3의 배수에 해당하는 값 모두 삭제
//리스트에 저장된 데이터를 순서대로 출력
int main(void){

    //ArrayList 생성 및 초기화
    List list;
    int data, i;
    int sum = 0;
    ListInit(&list);

    //데이터 저장
    for(int i=1; i<=9; i++)
        LInsert(&list, i);

    //합을 출력
    if(LFirst(&list, &data)) {

        sum += data;
        
        //연속으로 저장 된 데이터 모두 조회해서 더하기
        while(LNext(&list, &data))
            sum += data;
    }
    printf("저장된 데이터의 합 : %d\n", sum);

    //2의 배수와 3의 배수에 해당하는 값 모두 삭제
    if(LFirst(&list, &data)) {
        
        if(data%2==0 || data%3==0)
            LRemove(&list);

        while(LNext(&list, &data))
            if(data%2==0 || data%3==0)
                LRemove(&list);
    }
    
    //삭제 후 남은 데이터 출력
    printf("삭제 후 남은 데이터 : ");
    if(LFirst(&list, &data)) {
        printf("%d  ", data);

        while(LNext(&list, &data))
            printf("%d  ", data);
    }
    printf("\n");

    return 0;
}