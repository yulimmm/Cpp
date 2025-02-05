//Lv2 진정한 효도
#include <stdio.h>
int board[3][3];
int ground[3];

void groundRest()
{
  for(int i = 0; i < 3; i++) ground[i] = 0;
}

int getcost()
{
  int cost;
  if(ground[0]==3 || ground[1]==3 || ground[2]==3) cost = 0;
  else if(ground[0]==1 && ground[1]==1 && ground[2]==1) cost = 2;
  else if(ground[0]==1 && ground[2]==2 || ground[0]==2 && ground[2]==1) cost = 2;
  else cost = 1;
  return cost;
}

int main()
{
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      scanf("%d",&board[i][j]);
    }
  }

  int minCost = 100;

  //가로 검사
  for(int i = 0; i < 3; i++){
    groundRest();
    for(int j = 0; j < 3; j++){
      ground[board[i][j]-1]++;
    }
    int cost = getcost();
    if(cost==0) { printf("0"); return 0;}
    if(minCost > cost) minCost = cost;
  }

  //세로 검사
  for(int i = 0; i < 3; i++){
    groundRest();
    for(int j = 0; j < 3; j++){
      ground[board[j][i]-1]++;
    }
    int cost = getcost();
    if(cost==0) { printf("0"); return 0;}
    if(minCost > cost) minCost = cost;
  }

  printf("%d", minCost);
}
