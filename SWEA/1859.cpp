//백만 장자 프로젝트 Level D2
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  int TestCase, t;
  cin >> TestCase;
  for(int i = 1; i <= TestCase; i++){
    cin >> t;
    vector<int> arr(t);
    for(int j = 0; j < t; j++) cin >> arr[j];
    long long max_value = arr[t-1];
    long long max_sum = 0;
    for(int k = t-2; k >= 0; k--){
      if(max_value <= arr[k]) max_value = arr[k];
      else{
        max_sum += max_value-arr[k];
      }
    }
    cout<<'#'<<i<<' ';
    cout<<max_sum<<'\n';
  }

  return 0;
}
