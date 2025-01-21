#include <iostream>
#include <stack>
#include <string>
using namespace std;
int num = 1;
int ans = 0;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  string str;
  cin >> str;
  stack<char>st;
  for(int i = 0; i < str.size(); i++){
    if(str[i]=='('){
      num = num*2;
      st.push(str[i]);
    }
    else if(str[i]=='['){
      num = num*3;
      st.push(str[i]);
    }
    else if(str[i]==')'){
      if(st.empty() || st.top()!='('){
        cout<<0;
        return 0;
      }
      if(str[i-1]=='(') ans += num;
      num = num/2;
      st.pop();
    }
    else if(str[i]==']'){
      if(st.empty() || st.top()!='['){
        cout<<0;
        return 0;
      }
      if(str[i-1]=='[') ans += num;
      num = num/3;
      st.pop();
    }
  }
  if(st.empty()) cout<<ans;
  else cout<<0;
  return 0;
}
