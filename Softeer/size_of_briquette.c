//Lv2 연탄의 크기
#include <stdio.h>
int arr[100];

int main()
{
  int num;
  scanf("%d",&num);
  int tc = num;
  while(tc--){
    int inputVal;
    scanf("%d",&inputVal);
    int rad = 2;
    while(rad <= inputVal){
      if(inputVal%rad==0){
        arr[rad]++;
      }
      rad++;
    }
  }
  int max = 0;
  for(int i = 2; i <= 100; i++){
    if(max < arr[i]){
      max = arr[i];
    }
  }
  printf("%d",max);
}
