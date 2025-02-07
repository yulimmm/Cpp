#include <stdio.h>
#include <stdbool.h>
const int size = 10;
int stack[size];
int top = 0;

bool isEmpty()
{
  if(top < 0) return 1;
  return 0;
}

bool isFull()
{
  if(top==size-1) return 1;
  return 0;
}

void push(int num){
  if(isFull()) return;
  stack[top++] = num;
}

void pop(){
  if(isEmpty()) return;
  top--;
}

int main()
{
  push(1);
  push(2);
  push(3);
  pop();
  printf("%d", stack[top-1]);
}
