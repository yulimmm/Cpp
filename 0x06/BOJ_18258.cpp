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
      if(Q.empty()) cout<<-1<<'\n';
      else cout<<Q.front()<<'\n';
    }
    else if(cmd=="back"){
      if(Q.empty()) cout<<-1<<'\n';
      else cout<<Q.back()<<'\n';
    }
    else if(cmd=="size"){
      cout<<Q.size()<<'\n';
    }
    else if(cmd=="pop"){
      if(Q.empty()) cout<<-1<<'\n';
      else{
        cout << Q.front()<<'\n';
        Q.pop();
      }
    }
    else if(cmd=="empty"){
      cout<<Q.empty()<<'\n';
    }
  }
  return 0;
}
