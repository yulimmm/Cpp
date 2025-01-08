#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int arr1[26];
int arr2[26];
int ans = 0;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  string str1, str2;
  fill(arr1, arr1+26, 0);
  fill(arr2, arr2+26, 0);
  cin >> str1 >> str2;
  for(int i = 0; i < str1.size(); i++){
    int num = str1[i] - '0' - 49;
    arr1[num]++;
  }
  for(int i = 0; i < str2.size(); i++){
    int num = str2[i] - '0' - 49;
    arr2[num]++;
  }
  for(int i = 0; i < 26; i++){
    if(arr1[i]!=arr2[i]){
      int num = abs(arr1[i]-arr2[i]);
      ans += num;
    }
  }
  cout << ans;
  return 0;
}
