#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  string str;
  stack<char>st;
  int ans = 0;
  cin >> str;
  st.push(str[0]);
  for(int i = 1; i < str.size(); i++){
    if(str[i]=='(') st.push(str[i]);
    else{
      if(str[i-1]=='('){ //레이저
        st.pop();
        ans+=st.size();
      }
      else{ //막대
        st.pop();
        ans++;
      }
    }
  }
  cout<<ans;
  return 0;
}
