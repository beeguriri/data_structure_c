#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

void HeapInit(Heap *ph, PriorityComp pc) {
    ph->comp = pc;
    ph->numOfData = 0;
}

int IsEmpty(Heap *ph){

    if(ph->numOfData==0)
        return TRUE;
    return FALSE;
}

int GetParentIDX(int idx) {
    return idx/2;
}

int GetLeftChildIDX(int idx) {
    return idx*2;
}

int GetRightChildIDX(int idx) {
    return idx*2+1;
}

//최소힙 : 작은값이 우선순위 가짐
int GetHiPriChildIDX(Heap *ph, int idx) {

    //자식 노드가 존재하지 않으면
    if(GetLeftChildIDX(idx) > ph->numOfData)
        return 0;
    //자식노드가 하나만 존재하면
    else if (GetLeftChildIDX(idx) == ph->numOfData)
        return GetLeftChildIDX(idx);
    //자식노드가 둘다 존재하면 둘중에 작은 값이 우선순위 높음
    else {
        //오른쪽자식이 값이 작음
        if(ph->comp(
            ph->heapArr[GetLeftChildIDX(idx)], 
            ph->heapArr[GetRightChildIDX(idx)])<0)
                return GetRightChildIDX(idx);
        //왼쪽자식이 값이 작음
        else
            return GetLeftChildIDX(idx);
    }

}

void Insert(Heap *ph, Data data){
    
    //제일 마지막에 데이터 추가 후 교환
    int idx = ph->numOfData+1;

    while(idx!=1) {
        //data가 더 작으면(우선순위 높으면) 계속 반복
        if(ph->comp(data, ph->heapArr[GetParentIDX(idx)])>0) {

            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        } 
        else
            break;
    }

    ph->heapArr[idx] = data;
    (ph->numOfData)++;

}

Data Delete(Heap *ph) {

    //우선순위 높은순으로 꺼냄
    //루트노드 제거 후, 제일 마지막값을 루트노드에 배치하여
    //우선순위 비교
    Data delData = ph->heapArr[1];
    Data lastElm = ph->heapArr[ph->numOfData];

    int parentIDX = 1;
    int childIDX;

    //자식노드 둘중에 작은값
    while(childIDX = GetHiPriChildIDX(ph, parentIDX)) {

        //lastElm이 자식노드보다 작거나 같으면 반복문 종료
        if(ph->comp(lastElm, ph->heapArr[childIDX])>=0)
            break;

        ph->heapArr[parentIDX] = ph->heapArr[childIDX];
        parentIDX = childIDX;
        
    }

    ph->heapArr[parentIDX] = lastElm;
    (ph->numOfData)--;

    return delData;

}