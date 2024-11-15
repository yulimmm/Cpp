//공정한 분배 2 Level D3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, testCase;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> testCase;
  for(int t = 1; t <= testCase; t++){
    cin >> a >> b;
    vector<int>v(a);
    for(int i = 0; i < a; i++) cin >> v[i];
    int mindiff=1000000001;
    sort(v.begin(), v.end());
    for(int i = 0; i <= a-b; i++){
      int temp = v[b+i-1]-v[i];
      mindiff = min(mindiff, temp);
    }
    cout<<'#'<<t<<' '<<mindiff<<'\n';
  }
  return 0;
}
