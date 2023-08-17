#include <stdio.h>

int RecurBSearch(int arr[], int first, int last, int target)
{
    int mid;

    //종료조건 : first < last
    if(first>last)
        return -1;

    //mid를 절반으로 줄이면서 반복
    mid = (first+last)/2;

    if(arr[mid]==target)
        return mid;
    else if(arr[mid]<target)
        return RecurBSearch(arr, mid+1, last, target);
    else
        return RecurBSearch(arr, first, mid-1, target);
    
}

int main(void)
{
    int arr [] = {1, 3, 5, 7, 9};
    int idx;

    idx = RecurBSearch(arr, 0, sizeof(arr)/sizeof(int)-1, 7);
    if(idx==-1)
        printf("탐색 실패\n");
    else
        printf("타겟 인덱스 : %d\n", idx);

    idx = RecurBSearch(arr, 0, sizeof(arr)/sizeof(int)-1, 4);
    if(idx==-1)
        printf("탐색 실패\n");
    else
        printf("타겟 인덱스 : %d\n", idx);
    return 0;
}