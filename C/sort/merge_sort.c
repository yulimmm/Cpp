#include <stdio.h> //merge sort

// 두 개의 부분 배열을 병합하는 함수
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // 왼쪽 부분 배열 크기
    int n2 = right - mid;      // 오른쪽 부분 배열 크기

    int L[n1], R[n2];  // 임시 배열 생성

    // 데이터를 왼쪽과 오른쪽 부분 배열에 복사
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // 두 부분 배열을 병합
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])  // 안정 정렬 유지
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // 남아 있는 원소들을 복사
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// 병합 정렬 함수 (재귀적)
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // 중간 지점 계산

        mergeSort(arr, left, mid);  // 왼쪽 부분 정렬
        mergeSort(arr, mid + 1, right);  // 오른쪽 부분 정렬
        merge(arr, left, mid, right);  // 병합
    }
}

// 배열 출력 함수
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("정렬 전: ");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("정렬 후: ");
    printArray(arr, size);

    return 0;
}
