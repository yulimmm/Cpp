#include <stdio.h>
int a[100005];
int d[100005];

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

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1; i <= num; i++){
        d[i] = max(0, d[i-1]) + a[i];
    }
    int result = getMax(num);
    printf("%d", result);
}
