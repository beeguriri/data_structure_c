#include <stdio.h>

void ShellSort(int arr[], int n) {

    int i, j;
    int h;
    int target;

    h=n/2;

    while(h>0) {
        for(i=h; i<n; i++) {
            target = arr[i];
            // j = i-h;
            // while(j>=0 && arr[j]>target) {
            //     arr[j+h] = arr[j];
            //     j -= h;
            // }
            for(j=i-h; j>=0; j-=h) {
                if(arr[j]>target)
                    arr[j+h] = arr[j];
                else
                    break;
            }
            arr[j+h] = target;
        }
        
        for(int x=0; x<n; x++)
            printf("%d ", arr[x]);
        printf("\n");
        h/=2;
    }

}

int main(void) {

    int arr[10] = {9, 6, 5, 8, 10, 1, 3, 7, 4, 2};
    int i;

    ShellSort(arr, sizeof(arr)/sizeof(int));

}