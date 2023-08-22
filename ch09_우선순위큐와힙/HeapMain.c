#include <stdio.h>
#include "Heap.h"

int DataPriorityComp(char ch1, char ch2) {
    return ch2 - ch1;
}

int main(void) {

    Heap heap;
    HeapInit(&heap, DataPriorityComp);

    Insert(&heap, 'D');
    Insert(&heap, 'A');
    Insert(&heap, 'F');
    Insert(&heap, 'B');
    Insert(&heap, 'C');

    printf("%c ", Delete(&heap));
    printf("%c ", Delete(&heap));

    printf("\n");

    Insert(&heap, 'A');
    Insert(&heap, 'A');
    Insert(&heap, 'B');

    while(!IsEmpty(&heap))
        printf("%c ", Delete(&heap));

    return 0;
}