#include <stdio.h>
int d[505][505];
int input[505][505];

int max(int a, int b){
    if(a >= b) return a;
    else return b;
}

void debug(int floor)
{
    for(int f = 0; f < floor; f++){
        for(int i = 0; i <= f; i++){
            printf("%d ", d[f][i]);
        }
        printf("\n");
    }
}

int main()
{
    int floor;
    scanf("%d",&floor);
    for(int f = 0; f < floor; f++){
        for(int i = 0; i <= f; i++){
            int num;
            scanf("%d", &num);
            input[f][i] = num;
        }
    }
    d[0][0] = input[0][0];
    for(int f = 1; f < floor; f++){
        for(int i = 0; i <= f; i++){
            if(i==0) d[f][i] = d[f-1][i] + input[f][i];
            else if(i==f) d[f][i] = d[f-1][i-1] + input[f][i];
            else d[f][i] = max(d[f-1][i-1] + input[f][i], d[f-1][i] + input[f][i]);
        }
    }
    int ans = 0;
    for(int i = 0; i < floor; i++){
        ans = max(ans, d[floor-1][i]);
    }
    printf("%d",ans);
    //printf("\n\n");
    //debug(floor);
    return 0;
}
