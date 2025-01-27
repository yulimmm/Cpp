#include <stdio.h>
long long d[93][2]; //0으로 끝나는 거, 1로 끝나는 거

int main()
{
    int num;
    scanf("%d",&num);
    d[1][0] = 0;
    d[1][1] = 1;
    for(int i = 2; i <= num; i++){
        d[i][1] = d[i-1][0];
        d[i][0] = d[i-1][1] + d[i-1][0];
    }
    printf("%lld",d[num][0]+d[num][1]);
    return 0;
}

/*
1: 1
2: 10
3: 100 101
4: 1000 1010 1001 
5: 10000 10010 10100 10001 10101 
*/
