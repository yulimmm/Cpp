#include <iostream>
using namespace std;
int dp[15];
int testCase;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  dp[1] = 1;
  dp[2] = 2; //1+1, 2
  dp[3] = 4; //1+1+1, 1+2, 2+1, 3
  for(int i = 4; i < 11; i++){
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
  }
  cin >> testCase;
  while(testCase--){
    int num;
    cin >> num;
    cout<<dp[num]<<'\n';
  }
  return 0;
}
