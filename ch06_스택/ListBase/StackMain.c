#include <stdio.h>
#include "ListBaseStack.h"

int main(void) {

    Stack stack;
    StackInit(&stack);

    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);
    Push(&stack, 4);
    Push(&stack, 5);

    //데이터 있을때 peek
    printf("Peek : %d", Peek(&stack));
    printf("\n");
    
    //데이터 꺼내기
    while(!IsEmpty(&stack))
        printf("%d ", Pop(&stack));

    //데이터 비었을때 peek
    printf("Peek : %d", Peek(&stack));
    printf("\n");

}