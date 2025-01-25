#include <iostream>
using namespace std;
int n;
int a[505][505], d[505][505];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= i; ++j)
      cin >> a[i][j];
  d[1][1] = a[1][1];
  for(int i = 2; i <= n; ++i)
    for(int j = 1; j <= i; ++j)
      d[i][j] = max(d[i-1][j-1], d[i-1][j]) + a[i][j];
  cout << *max_element(d[n] + 1, d[n] + n + 1);
}
