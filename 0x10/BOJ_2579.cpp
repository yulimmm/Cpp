#include <iostream>
#include <algorithm>
using namespace std;
int d[302][3]; //현재까지 1: 한 번 밟음. 2: 두 번 밟음. 
int s[302];

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> s[i];
  if(n==1){
    cout<<s[1];
    return 0;
  }
  d[1][1] = s[1];
  d[1][2] = 0;
  d[2][1] = s[2];
  d[2][2] = s[1]+s[2];
  for(int i = 3; i <= n; i++){
    d[i][1] = max(d[i-2][1],d[i-2][2])+s[i];
    d[i][2] = d[i-1][1]+s[i];
  }
  cout<<max(d[n][1],d[n][2]);
  return 0;
}
