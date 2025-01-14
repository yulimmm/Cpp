#include <iostream>
#include <queue>
#include <string>
using namespace std;
int testCase;
queue<int>Q;
int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> testCase;
  while(testCase--){
    string cmd;
    cin >> cmd;
    if(cmd=="push"){
      int num;
      cin >> num;
      Q.push(num);
    }
    else if(cmd=="front"){
      if(Q.empty()) cout<<-1;
      else cout<<Q.front();
    }
    else if(cmd=="back"){
      if(Q.empty()) cout<<-1;
      else cout<<Q.back();
    }
    else if(cmd=="size"){
      cout<<Q.size();
    }
    else if(cmd=="pop"){
      if(Q.empty()) cout<<-1;
      else{
        cout << Q.front();
        Q.pop();
      }
    }
    else if(cmd=="empty"){
      cout<<Q.empty();
    }
  }
  return 0;
}
