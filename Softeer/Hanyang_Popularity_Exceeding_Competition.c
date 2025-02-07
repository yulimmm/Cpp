//Lv3 Hanyang Popularity Exceeding Competition
#include <stdio.h>
int X[200005];
int input[200005][2]; //P, C

int main(void)
{
    int num;
    scanf("%d",&num);
    for(int i = 1; i <= num; i++){
        scanf("%d %d",&input[i][0], &input[i][1]);
    }
    X[0] = 0; //처음 인기도
    for(int i = 1; i <= num; i++){
        if(abs(input[i][0]-X[i-1])<=input[i][1] ) {
            X[i]=X[i-1]+1;
        }
        else X[i] = X[i-1];
    }
    printf("%d",X[num]);

   return 0;
}
