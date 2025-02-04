//Lv2 X marks the Spot
#include <stdio.h>

int main()
{
  char st1[1000000];
  char st2[1000000];
  char ans[500005];
  int N;
  int idx = 0;
  scanf("%d",&N);
  int testCase = N;
  while(testCase--){
    scanf("%s %s",st1,st2);
    int i = 0;
    while(1){
      if(st1[i]=='x' || st1[i]=='X'){
        break;
      }
      i++;
    }
    ans[idx] = st2[i];
    idx++;
  }
  for(int i = 0; i < N; i++){
    char val = ans[i];
    int check = val - '0';
    if(check <= 74 && check >= 49){ //소문자
      printf("%c",val-32);
    }
    else printf("%c",ans[i]);
  }
  
}
