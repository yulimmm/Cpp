//Lv3 CPTI 테스트케이스 5개 실패...
#include <stdio.h>
#include <string.h>

#define MAX_N 30000
#define MAX_M 30

int N, M;
int cpti[MAX_N];  // 비트마스크 저장
int count = 0;

int hamming_distance(int a, int b) {
  int diff = a ^ b;  // XOR 연산
  return __builtin_popcount(diff);  // 1의 개수 반환
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++){
      int temp;
      scanf("%1d",&temp);
      if(temp==1){
        cpti[i] |= (1<<j);
      }
    }
  }

  // 모든 쌍 비교 (N log N 활용)
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (hamming_distance(cpti[i], cpti[j]) <= 2) {
        count++;
      }
    }
  }

  printf("%d\n", count);
  return 0;
}
