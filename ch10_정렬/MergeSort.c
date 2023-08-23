#include <stdio.h>
#include <stdlib.h>

void MergeArray(int arr[], int left, int mid, int right) {

    int pl = left;
    int pr = mid+1;
    int idx = left;

    int i;

    //임시배열 생성
    int *sortArr = (int*)malloc(sizeof(int)*(right+1));

    while(pl<=mid && pr<=right) {

        if(arr[pl]<=arr[pr])
            sortArr[idx++] = arr[pl++];
        else
            sortArr[idx++] = arr[pr++];
    }

    //오른쪽만 남음
    if(pl>mid)
        while(pr<=right)
            sortArr[idx++] = arr[pr++];
    //왼쪽만 남음
    else
        while(pl<=mid)
            sortArr[idx++] = arr[pl++];

    //정렬된 결과를 원래 배열에 반영
    for(i=left; i<=right; i++)
        arr[i] = sortArr[i];
    
}

void MergeSort(int arr[], int left, int right) {

    if(left>=right)
        return;

    int mid; 

    mid = (left+right)/2;

    //둘로 나눌수 있을때 까지 나눈 후
    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);

    //정렬된 두 배열 병합
    MergeArray(arr, left, mid, right);
}

int main(void) {

    int arr[10] = {9, 6, 5, 8, 10, 1, 3, 7, 4, 2};
    int i;

    MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);

    for(i=0; i<10; i++)
        printf("%d ", arr[i]);

    return 0;
}