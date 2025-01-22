#include <iostream>
#include <algorithm>
using namespace std;
int p[1005][3]; //price
int dp[1005][3];
int n;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++)
    for(int j = 0; j < 3; j++) cin >> p[i][j];
  dp[1][0] = p[1][0];
  dp[1][1] = p[1][1];
  dp[1][2] = p[1][2];
  for(int i = 2; i <= n; i++){
    for(int j = 0; j < 3; j++){
      dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + p[i][0];
      dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + p[i][1];
      dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + p[i][2];
    }
  }
  int ans = min(dp[n][0], dp[n][1]);
  cout << min(ans, dp[n][2]);
  return 0;
}
