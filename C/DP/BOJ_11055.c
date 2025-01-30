#include <stdio.h>
int a[1005];
int d[1005];

int max(int a, int b)
{
    if(a >= b) return a;
    return b;
}

int getMax(int num)
{
    int max = d[1];
    for(int i = 2; i <= num; i++){
        if(max <= d[i]) max = d[i];
    }
    return max;
}

void debug(int num)
{
    for(int i = 1; i <= num; i++){
        printf("%d ",d[i]);
    }
    printf("\n");
}

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++){
        scanf("%d",&a[i]);
        d[i] = a[i];
    }
    d[1] = a[1];
    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= i; j++){
            if(a[i]>a[j]) d[i] = max(d[i], d[j]+a[i]);
        }
    }
    int result = getMax(num);
    printf("%d\n", result);
    //debug(num);
}
