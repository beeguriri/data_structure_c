#include <stdio.h>
#include "PointArrayList.h"

//초기화
void ListInit(List *plist){
    (plist -> numOfData) = 0;       //데이터의 개수 : 0
    (plist -> curPosition) = -1;    //포인터의 위치 : -1
}

//데이터 저장
void LInsert(List *plist, LData data){

    if(plist -> numOfData >= LIST_LEN) {
        puts("저장할 공간이 없습니다.");
        return;
    }

    plist -> arr[plist -> numOfData] = data;    //데이터 저장
    (plist -> numOfData)++;                     //데이터 수 증가
}

//첫번째 데이터 참조
int LFirst(List *plist, LData *pdata){

    if(plist -> numOfData == 0)
        return FLASE;

    (plist->curPosition) = 0; //참조 위치 초기화
    *pdata = plist -> arr[0]; //pdata에 데이터 저장

    return TRUE;
}

//두번째 이후 데이터 참조
int LNext(List *plist, LData *pdata){

    //더이상 참조 할 데이터 없음
    if(plist -> curPosition >= (plist -> numOfData)-1)
        return FLASE;

    (plist -> curPosition)++; //참조 위치 증가
    *pdata = plist -> arr[plist -> curPosition]; //pdata에 데이터 저장

    return TRUE;
}

//데이터 삭제
LData LRemove(List *plist){

    int rpos = plist -> curPosition;
    int num = plist -> numOfData;
    int i;
    LData rdata = plist -> arr[rpos]; //삭제할 데이터 임시 저장

    //삭제를 위한 데이터의 이동
    for(i=rpos; i<num-1; i++)
        plist -> arr[i] = plist -> arr[i+1];
    
    //기존 데이터가 한칸씩 앞으로 당겨졌으므로
    //이전까지 참조했던 위치로 옮기기 위함
    (plist -> curPosition)--;

    //데이터 삭제로 전체 수 감소
    (plist -> numOfData)--;

    return rdata;
}

//저장된 데이터의 수 반환
int LCount(List *plist){
    return plist -> numOfData;
}

//현재 커서 위치 반환
int LCursor(List *plist){
    return plist -> curPosition;
}