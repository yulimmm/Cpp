#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int testCase;
string s, e;

bool solution()
{
  while(s.size()<e.size()){
    if(e.back()=='X'){
      e.pop_back();
    }
    else if(e.back()=='Y'){
      e.pop_back();
      reverse(e.begin(),e.end());
    }
  }
  return e==s;
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> testCase;
  for(int i = 1; i <= testCase; i++){
    cin >> s >> e;
    cout<<'#'<<i<<' ';
    if(solution()) cout<<"Yes\n";
    else cout<<"No\n";
  }

  return 0;
}
