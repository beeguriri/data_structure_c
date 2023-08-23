#include <stdio.h>

void InsertionSort(int arr[], int n) {

    int i, j;
    int target;

    for(i=1; i<n; i++) {
        target = arr[i];
        
        // j = i-1;

        // while(j>=0 && arr[j]>target) {
        //     arr[j+1] = arr[j];
        //     j--;
        // }

        for(j=i-1; j>=0; j--){
            if(arr[j]>target)
                arr[j+1] = arr[j];  //비교대상 한칸씩 밀기
            else
                break;
        }
        
        arr[j+1] = target;
    }
}


int main(void) {

    int arr [4] = {3, 2, 4, 1};
    int i;

    InsertionSort(arr, sizeof(arr)/sizeof(int));

    for(i=0; i<4; i++)
        printf("%d ", arr[i]);

    printf("\n");


    return 0;
}