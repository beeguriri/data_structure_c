#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void) {

    Stack stack;
    StackInit(&stack);

    Push(&stack, 1);    Push(&stack, 2);
    Push(&stack, 3);    Push(&stack, 4);
    Push(&stack, 5);    
    //Push(&stack, 6);    "스택이 가득 찼습니다!!""

    //peek
    printf("제일 위에 있는 데이터 : %d", Peek(&stack));

    //pop
    printf("\n스택에서 데이터 제거 : ");
    while(!IsEmpty(&stack))
        printf("%d ", Pop(&stack));

    //peek
    //printf("제일 위에 있는 데이터 : %d", Peek(&stack));  "스택이 비었습니다!!"

}