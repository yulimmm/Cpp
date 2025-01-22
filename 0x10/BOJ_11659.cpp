#include <iostream>
using namespace std;
int n, m;
int input[100003];
int dp[100003];

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> input[i];
  dp[0] = 0;
  dp[1] = input[1];
  for(int i = 2; i <= n; i++) dp[i] = dp[i-1] + input[i];
  while(m--){
    int i, j;
    cin >> i >> j;
    cout << dp[j] - dp[i-1] <<'\n';
  }
  return 0;
}
