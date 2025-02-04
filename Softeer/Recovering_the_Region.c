//Lv2 Recovering the Region
#include <stdio.h>
int board[55][55];

int main()
{
  int num;
  scanf("%d",&num);
  for(int i = 0; i < num; i++){
    for(int j = 0; j < num; j++){
      scanf("%d",&board[i][j]);
    }
  }
  int group = 1;
  for(int i = 0; i < num; i++){
    for(int j = 0; j < num; j++){
      printf("%d ",group);
    }
    printf("\n"); group++;
  }
  return 0;
}
