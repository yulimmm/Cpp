#include <stdio.h> //퀵 정렬

// 두 개의 값을 교환하는 함수
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 배열을 분할하고 피벗의 위치를 반환하는 함수
int partition(int arr[], int left, int right) {
    int pivot = arr[right]; // 마지막 요소를 피벗으로 선택
    int i = left - 1; // 작은 요소들의 인덱스
    
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) { // 피벗보다 작은 경우
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]); // 피벗을 올바른 위치로 이동
    return i + 1; // 피벗의 최종 위치 반환
}

// 퀵 정렬 함수 (재귀적)
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right); // 피벗을 기준으로 분할
        quickSort(arr, left, pivotIndex - 1);  // 왼쪽 부분 정렬
        quickSort(arr, pivotIndex + 1, right); // 오른쪽 부분 정렬
    }
}

// 배열 출력 함수
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("정렬 전: ");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("정렬 후: ");
    printArray(arr, size);

    return 0;
}
