//View Level D3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  int TestCase = 10, t;
  for(int i = 1; i <= TestCase; i++){
    int ans = 0;
    cin >> t;
    vector<int> arr(t);
    for(int j = 0; j < t; j++) cin >> arr[j];
    for(int k = 2; k < t-2; k++){
      if(arr[k-2]>=arr[k] || arr[k-1]>=arr[k]) continue;
      if(arr[k+1]>=arr[k] || arr[k+2]>=arr[k]) continue;
      int able = arr[k]-arr[k-2];
      able = min(able, arr[k]-arr[k-1]);
      able = min(able, arr[k]-arr[k+1]);
      able = min(able, arr[k]-arr[k+2]);
      ans += able;
    }
    cout<<'#'<<i<<' ';
    cout<<ans<<'\n';
  }

  return 0;
}
