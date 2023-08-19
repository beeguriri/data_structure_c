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