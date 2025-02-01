#include <stdio.h>

int t[55];
int p[1005];
long long d[1500005]; // i번째 일에 상담을 시작했을 때 얻을 수 있는 최대 수익

long long getMax(int num)
{
    long long max = d[1];
    for(int i = 2; i <=num; i++){
        if(max < d[i]) max = d[i];
    }
    return max;
}

int max(int a, int b)
{
    if(a <= b) return b;
    return a;
}

void debug(int num)
{
    for(int i = 1; i <= num; i++) printf("%lld ", d[i]);
}

int main(void){  
  int n;
  scanf("%d", &n);
  
  for (int i = 1; i <= n; i++) scanf("%d %d",&t[i],&p[i]);
  
  for (int i = n; i >= 1; i--) {
    // i번째 일에 상담을 할 수 있을 경우
    if (i + t[i] <= n + 1) {
      // i번째 일에 상담을 했을 때와 상담을 하지 않았을 때 얻을 수 있는 수익 중 최대 수익을 취함
      d[i] = max(d[i + t[i]] + p[i], d[i + 1]);
    }
    else d[i] = d[i + 1];
  }
  printf("%lld\n",getMax(n));
  //debug(n);
}
