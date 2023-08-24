#include <stdio.h>

int swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int n, int i) {
    int parent = i;
    int leftChild = i*2+1;
    int rightChild = i*2+2;

    // 왼쪽 자식 노드가 존재하면서 부모노드와 값 비교.
    if (leftChild < n && array[parent] < array[leftChild]) 
        parent = leftChild;
    
    // 오른쪽 자식 노드가 존재하면서 부모노드와 값 비교.
    if (rightChild < n && array[parent] < array[rightChild])
        parent = rightChild;
    
    // 왼쪽 or 오른쪽 자식 노드 중 부모 노드보다 큰 값이 존재한 경우
    if (i != parent) {
        swap(&array[parent], &array[i]);
        // 초기 부모노드가 제자리를 찾을 때까지 내려감
        heapify(array, n, parent);
    }
}

void heapSort(int array[], int n) {
    // 최대 힙(Max Heap) 구성
    for (int i = (n/2)-1; i >= 0; i--)
        heapify(array, n, i);

    // Root에 위치한 최대값을 마지막 노드와 바꿔가며 Heap 재구성
    // Heap의 크기를 줄여가며 값이 큰 원소를 차례로 가져옴
    for (int i = n - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

int main(void) {
    int n = 9;
    int array[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };

    heapSort(array, n);

    for (int i = 0; i < n; i++) 
        printf("%d ", array[i]);

    return 0;
}