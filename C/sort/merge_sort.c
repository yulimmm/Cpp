#include <stdio.h>
int sorted[1000]; // temp memory

void merge(int arr[], int left, int middle, int right)
{
  int n1 = left;
  int n2 = middle+1;
  int idx = left;
  while(n1 <= middle && n2 <= right){
    if(arr[n1] < arr[n2]){
      sorted[idx] = arr[n1];
      n1++;
    }
    else{
      sorted[idx] = arr[n2];
      n2++;
    }
    idx++;
  }
  if(n1 <= middle){
    while(n1 <= middle){
      sorted[idx] = arr[n1];
      n1++; idx++;
    }
  }
  else{
    while(n2 <= right){
      sorted[idx] = arr[n2];
      n2++; idx++;
    }
  }
  for(int i = left; i <= right; i++) arr[i] = sorted[i];
}

void mergeSort(int arr[], int left, int right)
{
  if(left >= right) return;
  int middle = left + (right - left) / 2;
  mergeSort(arr, left, middle);
  mergeSort(arr, middle+1, right);
  merge(arr, left, middle, right);
}

int main()
{
  const int size = 10;
  int arr[size] = {9,8,3,5,6,7,1,2,6,10};
  mergeSort(arr, 0, size - 1);
  for(int i = 0; i < size; i++) printf("%d ",arr[i]);
}
