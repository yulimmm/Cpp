#include <iostream>
#include <algorithm>
using namespace std;

int stage[305];
int s[305];
int n;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  int tot = 0;
  for(int i = 1; i <= n; i++){
    cin >> s[i];
    tot += s[i];
  }
  //i번째 계단까지 올라섰을 때 밟지 않아야 하는 계단의 최소값. 단 i번째 계단은 반드시 밟지 않을 계단으로 선택해야 함. 
  //초기값
  stage[1] = s[1];
  stage[2] = s[2];
  stage[3] = s[3];
  //점화식
  for(int i = 4; i <= n; i++){
    stage[i] = min(stage[i-2],stage[i-3])+s[i];
  }
  cout<<tot-min(stage[n-1],stage[n-2]);
  return 0;
}
