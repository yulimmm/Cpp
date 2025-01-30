#include <stdio.h>
long long d[103];

int main()
{
    d[1] = 1;
    d[2] = 1;
    d[3] = 1;
    d[4] = 2;
    d[5] = 2;
    for(int i = 6; i <= 100; i++){
        d[i] = d[i-1]+d[i-5];
    }
    int testCase;
    scanf("%d", &testCase);
    while(testCase--){
        int num;
        scanf("%d", &num);
        printf("%lld\n",d[num]);
    }
}
