//22574. 높은 곳으로 Level D3
#include <iostream>
using namespace std;

int testCase;

long long solve(int n, int p){
  long long ans = 0;
  for(int i = 0; i <= n; i++){
    ans = ans+i;
    if(ans == p) ans--;
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> testCase;
  for(int t = 0; t < testCase; t++){
    int n, p;
    cin >> n >> p;
    cout << solve(n, p) << '\n';
  }
  return 0;
}
