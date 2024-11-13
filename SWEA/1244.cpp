//1244 최대 상금 Level D3 
#include<iostream>
#include <algorithm>
#include <string>

using namespace std;

int mx,c;
string s;
void dfs(int idx, int cnt) {
  if(cnt==c) {
    mx=max(stoi(s),mx);
    return;
  }
  
  for(int i=idx;i<s.size()-1;i++) {
    for(int j=i+1;j<s.size();j++) {
      swap(s[i],s[j]);
      dfs(i,cnt+1);
      swap(s[i],s[j]);
    }
  }
}

int main()
{
  int t;
  cin >> t;
  for(int i=1;i<=t;i++) {
    cin >> s >> c;
    mx=-1;
    if(c>s.size()) c=s.size();
    dfs(0,0);
    cout << '#'<<i<<" " << mx<< '\n';
  }
  return 0;
}
