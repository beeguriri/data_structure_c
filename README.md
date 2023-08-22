# data_structure_c
C언어를 이용한 자료구조 공부하기

```shell
# 헤더파일 있을 때 컴파일 및 실행
$ gcc -c -o ArrayList.o ArrayList.c
$ gcc -c -o ListMain.o ListMain.c
$ gcc -o ListMain.exe ListMain.o ArrayList.o
$ .\ListMain.exe
```

## LinkedList
- 헤더는 더미 노드를 가르킴
- 더미 노드 이후로 데이터 추가
```c
typedef struct _node
{
    LData data;
    struct _node *next;
} Node;

typedef struct _linkedList
{
    Node *head;     //더미노드 가르킴
    Node *cur;      //탐색 및 삭제 노드 가르킴
    Node *before;   //삭제시 cur의 위치 조절 위함 

    int numOfData;
    int (*comp)(LData d1, LData d2);    //정렬 기준
} LinkedList;
```

## Doubly-LinkedList
- 노드는 이전노드, 다음노드의 연결을 가짐
```c
typedef struct _node {
    Data data;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct _dbDLinkedList{
    Node *head;
    Node *tail;
    Node *cur;      //현재위치

    int numOfData;  //데이터의 개수
} DBDLinkedList;
```
- 새로운 노드의 추가
    - 리스트의 제일 마지막에 추가 == 꼬리노드 직전에 추가
```c
void LInsert(List *plist, Data data) {

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;

    newNode -> next = plist -> tail;
    newNode -> prev = plist -> tail -> prev;
    plist -> tail -> prev -> next = newNode;
    plist -> tail -> prev = newNode;

    (plist -> numOfData)++;
}
```

- 노드의 삭제
    - 리스트에서 삭제할 노드를 찾고 (=>`cur`의 위치)
    - 연결을 바꿔줌
```c
Data LRemove(List *plist) {

    Node *rpos = plist -> cur;
    Data rdata = rpos -> data;

    //연결 바꿔주고
    plist -> cur -> prev -> next = plist -> cur -> next;
    plist -> cur -> next -> prev = plist -> cur -> prev;

    //현재위치 조정
    plist -> cur = plist -> cur -> prev;

    free(rpos);
    (plist -> numOfData)--;

    return rdata;
}
```

## Stack
- 배열로 stack 구현 : `topIndex`
```c
typedef int Data;

typedef struct _arrayStack {
    Data stackArr[STACK_LEN];
    int topIndex;
} ArrayStack;

//init
pstack -> topIndex = -1;
//push
pstack -> stackArr[++(pstack->topIndex)] = data;
//peek
pstack -> stackArr[pstack -> topIndex];
//pop
pstack -> stackArr[(pstack->topIndex)--];
```
- 리스트로 stack 구현 : `head`
```c
typedef struct _node {
    Data data;
    struct _node *next;
} Node;

//array의 topIdx == head
typedef struct _listStack {
    Node *head;
} ListStack;

//init
pstack -> head = NULL;
//push
newNode -> next = pstack -> head;
pstack -> head = newNode;
//peek
pstack -> head -> data;
//pop
rNode = pstack -> head;
pstack -> head = pstack -> head -> next;
```

## Queue
- 배열로 queue 구현 (원형큐)
```c
typedef struct _cQueue {
    int front;
    int rear;
    Data queArr[QUE_LEN];
} CQueue;

//초기화 시 front, rear 모두 0을 가르킴
void QueueInit(Queue *pq) {
    pq -> front = 0;
    pq -> rear = 0;
}

//배열 중 0번 index는 사용하지 않음 (포화 판단을 위해)
pq -> front == pq -> rear //배열 비었음
pq -> front == (pq -> rear + 1) % QUE_LEN //배열 가득참

//입력은 rear 포인트 증가
pq -> rear = (pq -> rear + 1) % QUE_LEN;
//출력은 front 포인트 증가
pq -> front = (pq -> front + 1) % QUE_LEN;
```
- 리스트로 queue 구현
```c
typedef struct _node {
    Data data;
    struct _node *next;
} Node;

typedef struct _lQueue {
    Node *front;
    Node *rear;
} LQueue;

void QueueInit(Queue *pq) {
    pq->front = NULL;
    pq->rear = NULL;
}

//enqueue
pq->rear->next = newNode;
pq->rear = newNode;

//dequeue
delNode = pq->front;
pq->front = pq->front->next;

//peek
pq->front->data;
```
- 이중연결리스트로 deque 구현
```c
typedef struct _node {
    Data data;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct _dlDeque {
    Node *head;
    Node *tail;
} DLDeque;

//앞에 데이터 추가할 때
newNode->prev = NULL;
newNode->next = pdq->head;
pdq->head->prev = newNode;
pdq->head = newNode;

//뒤에 데이터 추가할 때
newNode->prev = pdq->tail;
newNode->next = NULL;
pdq->tail->next = newNode;
pdq->tail = newNode;

//앞에 데이터 삭제할 때
Node *delNode = pdq->head;
pdq->head = pdq->head->next;
pdq->head->prev = NULL;

//뒤에 데이터 삭제할 때
Node *delNode = pdq->tail;
pdq->tail = pdq->tail->prev;
pdq->tail->next = NULL;
```

## Tree
- 리스트로 트리 구현하기
```c
typedef struct _bTreeNode {
    Data data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) {

    //기존에 서브트리가 있으면, 기존 서브트리 삭제
    if(main->left != NULL)
        free(main->left);
    
    //새로 만든 서브트리 넣어줌
    main->left = sub;
}
```
- 트리의 순회
```c
void InorderTraverse(BTreeNode *bt) {

    if(bt==NULL)
        return;

    InorderTraverse(bt->left);
    printf("%d ", bt->data);
    InorderTraverse(bt->right);
}

void PreorderTraverse(BTreeNode *bt) {

    if(bt==NULL)
        return;

    printf("%d ", bt->data);
    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode *bt) {

    if(bt==NULL)
        return;

    PostorderTraverse(bt->left);
    PostorderTraverse(bt->right);
    printf("%d ", bt->data);

}
```