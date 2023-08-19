#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} Node;

int main(void) {

    Node *head = NULL;
    Node *tail = NULL;
    Node *cur = NULL;

    Node *newNode = NULL;
    int readData;

    //head -> dummy 가르키도록
    head = (Node*)malloc(sizeof(Node));
    tail = head;

    //데이터 입력 (dummy 뒤로 추가하기)
    while(1){
        printf("자연수 입력: ");
        scanf("%d", &readData);

        if(readData<1)
            break;

        newNode = (Node*)malloc(sizeof(Node));
        newNode -> data = readData;
        newNode -> next = NULL;

        tail -> next = newNode;
        tail = newNode;
    }
    printf("\n");

    //데이터 출력하기
    printf("입력받은 데이터 전체 출력");
    
    if(head==tail)
        printf("저장된 데이터 없음");
    else {

        cur = head;

        while(cur->next != NULL) {
            cur = cur -> next;
            printf("%d ", cur->data);
        }
    }
    printf("\n\n");
    
    //메모리 해제
    if(head==tail)
        return 0;

    Node *delNode = head;
    Node *delNextNode = head -> next;

    while(delNextNode != NULL){
        delNode = delNextNode;
        delNextNode = delNextNode -> next;
        printf("%d 삭제 \n", delNode->data);
        free(delNode);
    }

    return 0;
}