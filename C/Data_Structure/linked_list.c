#include <stdio.h>

struct node{
  int data;
  struct node * nxt;
};

struct node arr[10];

int main()
{
  arr[0].data = 10;
  arr[0].nxt = &arr[3];
  arr[3].data = 100;
  arr[3].nxt = &arr[2];
  arr[2].data = 1;
  arr[2].nxt = &arr[1];
  arr[1].data = 5;
  arr[1].nxt = NULL;
  printf("%d\n",arr[2].nxt->data);
  struct node *current = &arr[0]; // 시작 주소
  while(current!=NULL){
    printf("%d ",current->data);
    current = current->nxt;
  }
}
