#ifndef __ARRAY_LIST_H__

#define __ARRAY_LIST_H__
#define TRUE 1
#define FLASE 0
#define LIST_LEN 100

typedef int LData;  //리스트에 int형 데이터 저장을 위한 선언

//배열 기반 리스트를 정의한 구조체
typedef struct __ArrayList {
    LData arr[LIST_LEN];
    int numOfData;
    int curPosition;
} ArrayList;

typedef ArrayList List; //배열기반 리스트 선언

void ListInit(List *plist);             //초기화
void LInsert(List *plist, LData data);  //데이터 저장
int LFirst(List *plist, LData *pdata);  //첫번째 데이터 참조
int LNext(List *plist, LData *pdata);   //두번째 이후 데이터 참조
LData LRemove(List *plist);             //데이터 삭제
int LCount(List *plist);                //저장된 데이터의 수 반환
int LCursor(List *plist);                //조회 시 커서 위치 반환

#endif
