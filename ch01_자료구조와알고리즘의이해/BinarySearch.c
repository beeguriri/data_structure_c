#include <stdio.h>

int BSearch(int arr[], int len, int target)
{
    int first = 0;
    int last = len-1;
    int mid;
    int opCount=0;

    while(first <= last)
    {
        mid = (first+last)/2;

        if(arr[mid]==target) 
        {
            //탐색 성공 시 연산횟수 출력
            printf("비교연산 횟수 : %d\n", opCount);
            return mid;
        }
        else 
        {
            if(arr[mid]<target)
                first = mid+1;
            else
                last = mid-1;
        }
        opCount++;
    }
    
    printf("비교연산 횟수 : %d\n", opCount);
    return -1;
}


int main(void)
{
    int arr [] = {1, 3, 5, 7, 9};
    int idx;

    idx = BSearch(arr, sizeof(arr)/sizeof(int), 7);
    if(idx==-1)
        printf("탐색 실패\n");
    else
        printf("타겟 인덱스 : %d\n", idx);

    idx = BSearch(arr, sizeof(arr)/sizeof(int), 4);
    if(idx==-1)
        printf("탐색 실패\n");
    else
        printf("타겟 인덱스 : %d\n", idx);


    //최악의 경우 확인
    int arr1 [500] = {0, };
    int arr2 [5000] = {0, };
    int arr3 [50000] = {0, };

    idx = BSearch(arr, sizeof(arr1)/sizeof(int), 1);
    if(idx==-1)
        printf("탐색 실패\n");
    else
        printf("타겟 인덱스 : %d\n", idx);

    idx = BSearch(arr, sizeof(arr2)/sizeof(int), 1);
    if(idx==-1)
        printf("탐색 실패\n");
    else
        printf("타겟 인덱스 : %d\n", idx);

    idx = BSearch(arr, sizeof(arr3)/sizeof(int), 1);
    if(idx==-1)
        printf("탐색 실패\n");
    else
        printf("타겟 인덱스 : %d\n", idx);
        
    return 0;
}