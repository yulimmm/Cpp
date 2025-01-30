#include <stdio.h>
int a[1005];
int d[1005];

int max(int a, int b){
    if(a > b) return a;
    return b;
}

int getMax(int num)
{
    int max = d[0];
    for(int i = 1; i < num; i++){
        if(max < d[i]) max = d[i];
    }
    return max;
}

int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        scanf("%d", &a[i]);
        d[i] = 1;
    }
    for(int i = 0; i < num; i++){
        for(int j = 0; j < i; j++){
            if(a[i]>a[j]) d[i] = max(d[i],d[j]+1);
        }
    }
    int result = getMax(num);
    printf("%d", result);
}
