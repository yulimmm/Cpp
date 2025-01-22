#include <iostream>
#include <algorithm>
using namespace std;
int d[1005];
int n;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  d[1] = 1;
  d[2] = 2;
  for(int i = 3; i <= n; i++){
    d[i] = (d[i-1]+d[i-2]) % 10007;
  }
  cout << d[n];
  return 0;
}
//d[1] = 1 => 1
//d[2] = 2 => 11,2
//d[3] = 3 => 111,21,12
//d[4] = 5 => 1111,121,211,112,22
