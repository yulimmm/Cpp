#include <iostream>
#include <string>
using namespace std;
int testCase;
int isused[26];

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> testCase;
  for(int tc = 0; tc < testCase; tc++){
    fill(isused, isused+26, 0);
    string orignStr, testStr;
    cin >> orignStr;
    for(int i = 0; i < orignStr.size(); i++){
      int charnum = (orignStr[i]-'0') - 49;
      isused[charnum]++;
    }
    cin >> testStr;
    for(int i = 0; i < testStr.size(); i++){
      int charnum = (testStr[i]-'0') - 49;
      isused[charnum]--;
    }
    int idx = 0;
    bool success=1;
    while(idx<26){
      if(isused[idx]!=0){
        success = 0;
        break;
      }
      idx++;
    }
    if(success) cout<<"Possible\n";
    else cout<<"Impossible\n";
  }
  return 0;
}
