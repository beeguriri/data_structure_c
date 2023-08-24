#include <stdio.h>

void Swap(int arr[], int idx1, int idx2) {
    
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

void QuickSort(int arr[], int left, int right) {

    int pivot = arr[left]; //제일 왼쪽을 피봇으로 잡음
    int pl = left + 1;
    int pr = right;

    while(pl <= pr) {
        while(arr[pl]<=pivot && pl<=right)    pl++;
        while(arr[pr]>=pivot && pr>=(left+1))    pr--;  //가장 왼쪽에 있는 피벗 제외해주기 위함

        //교차되지 않은 상태에서 pl, pr이 탐색을 마치면 교환 후
        //pl, pr이 교차될 때 까지 반복
        if(pl<=pr) 
            Swap(arr, pl, pr);   

    }

    //현재 제일 왼쪽 피봇 기준으로 정렬되어있는 상태이므로
    //피봇을 교차지점으로 보내주면
    //피봇을 중심으로 왼쪽이 작은값, 오른쪽이 큰값으로 정렬 되어 있음
    //pl과 pr이 교차되어 있는 상황이므로 left와 pr을 교환함
    Swap(arr, left, pr);

    if(left<pr) QuickSort(arr, left, pr-1);
    if(pl<right) QuickSort(arr, pr+1, right);
}

int main(void) {

    // int arr[10] = {9, 6, 5, 8, 10, 1, 3, 7, 4, 2};
    int arr[10] = {9, 9, 4, 3, 1, 1, 1, 2, 4, 2};

    int i;

    QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);

    for(i=0; i<10; i++)
        printf("%d ", arr[i]);

    return 0;
}