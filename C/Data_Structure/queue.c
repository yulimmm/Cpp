#include <stdio.h>
const int size = 10;
int queue[size];
int rear = 0, front = 0;

int isEmpty()
{
  if(rear==front) return 1;
  return 0;
}

int isFull()
{
  if((rear+1)%size == front) return 1;
  return 0;
}

void pop()
{
  if(isEmpty()){
    printf("is Empty\n");
    return;
  }
  front = (front+1)%size;
}

void push(int num)
{
  if(isFull()){
    printf("is full\n");
    return;
  }
  queue[rear] = num;
  rear = (rear+1)%size;
}

int getFront()
{
  return queue[front];
}

int getRear()
{
  return queue[(rear-1+size)%size];
}

int main()
{
  pop();
  push(1);
  push(2);
  printf("front:%d rear:%d\n",getFront(), getRear());
  pop();
  printf("front:%d rear:%d\n",getFront(), getRear());
}
