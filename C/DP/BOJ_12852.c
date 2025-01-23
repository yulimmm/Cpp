#include <stdio.h>
int d[1000003];
int path[1000003];

int main()
{
    int n;
    scanf("%d",&n);
    d[1] = 0;
    path[1] = 0;
    for(int i = 2; i <= n; i++){
        d[i] = d[i-1] + 1;
        path[i] = i-1;
        if(i%2==0 && d[i]>d[i/2]+1){
            d[i] = d[i/2]+1;
            path[i] = i/2;
        }
        if(i%3==0 && d[i]>d[i/3]+1){ 
            d[i] = d[i/3]+1;
            path[i] = i/3;
        }
    }

    printf("%d\n",d[n]);
    int k = n;
    while(1){
        if(k==0) break;
        printf("%d ",k);
        k = path[k];
    }
}
