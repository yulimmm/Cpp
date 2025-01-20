#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  int testCase, ans = 0;
  string str;
  cin >> testCase;
  while(testCase--){
    cin >> str;
    stack<char>ab;
    ab.push(str[0]);
    for(int i = 1; i < str.size(); i++){
      if(!ab.empty() && ab.top()==str[i]) ab.pop();
      else ab.push(str[i]);
    }
    if(ab.empty()) ans++;
  }
  cout<<ans;
  return 0;
}
