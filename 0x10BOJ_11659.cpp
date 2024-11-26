#include <iostream>
using namespace std;
int n, testcase;
int d[1000003];

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> testcase;
  d[0] = 0;
  for(int i = 1; i <= n; i++){
    int temp;
    cin >> temp;
    d[i] = d[i-1] + temp;
  }
  for(int t = 0; t < testcase; t++){
    int i, j;
    cin >> i >> j;
    cout<<d[j] - d[i-1] <<'\n';
  }
  return 0;
}
