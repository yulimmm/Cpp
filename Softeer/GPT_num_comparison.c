//Lv2 GPT식 숫자 비교
#include <stdio.h>
int size;
struct num{
  int a; // . 앞 
  int b; // . 뒤
};
struct num sorted[1005];

void merge(struct num arr[], int left, int middle, int right)
{
  int n1 = left;
  int n2 = middle+1;
  int idx = left;
  while(n1 <= middle && n2 <= right){
    if(arr[n1].a < arr[n2].a){
      sorted[idx++] = arr[n1++];
    }
    else{
      sorted[idx++] = arr[n2++];
    }
  }
  if(n1 <= middle){
    while(n1 <= middle) sorted[idx++] = arr[n1++];
  }
  else{
    while(n2 <= right) sorted[idx++] = arr[n2++];
  }
  for(int i = left; i <= right; i++) arr[i] = sorted[i];
}

void mergeSort(struct num arr[], int left, int right)
{
  if(left >= right) return;
  int middle = (left + right) / 2;
  mergeSort(arr, left, middle);
  mergeSort(arr, middle+1, right);
  merge(arr, left, middle, right);
}

void merge2(struct num arr[], int left, int middle, int right)
{
  int n1 = left;
  int n2 = middle+1;
  int idx = left;
  while(n1 <= middle && n2 <= right){
    if(arr[n1].b < arr[n2].b){
      sorted[idx++] = arr[n1++];
    }
    else{
      sorted[idx++] = arr[n2++];
    }
  }
  if(n1 <= middle){
    while(n1 <= middle) sorted[idx++] = arr[n1++];
  }
  else{
    while(n2 <= right) sorted[idx++] = arr[n2++];
  }
  for(int i = left; i <= right; i++) arr[i] = sorted[i];
}

void mergeSort2(struct num arr[], int left, int right)
{
  if(left >= right) return;
  int middle = (left + right) / 2;
  mergeSort2(arr, left, middle);
  mergeSort2(arr, middle+1, right);
  merge2(arr, left, middle, right);
}


void printArr(struct num arr[])
{
  for(int i = 0; i < size; i++){
    if(arr[i].b==-1) printf("%d\n",arr[i].a);
    else printf("%d.%d\n",arr[i].a, arr[i].b);
  }
}

int main()
{
  struct num input[1005];
  scanf("%d", &size);
  for(int i = 0; i < size; i++){
    int a, b = -1;
    int count = scanf("%d.%d", &a, &b);
    if(count == 1){
      input[i].a = a;
      input[i].b = -1;
    }
    else if(count == 2){
      input[i].a = a;
      input[i].b = b;
    }
  }
  mergeSort(input, 0, size-1);

  int n1Idx = 0;
  int n2Idx = 1;
  while(n1Idx < size){
    if(input[n1Idx].a == input[n2Idx].a){
      while(input[n1Idx].a == input[n2Idx].a){
        n2Idx++;
      }
      mergeSort2(input, n1Idx, n2Idx-1);
      n1Idx = n2Idx;
      n2Idx = n2Idx + 1;
    }
    else{
      n1Idx++; n2Idx++;
    }
  }
  printArr(input);
}
