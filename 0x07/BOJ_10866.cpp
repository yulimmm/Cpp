#include <iostream>
#include <deque>
#include <string>
using namespace std;
int testCase;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> testCase;
  deque<int>Q;
  while(testCase--){
    string cmd;
    cin >> cmd;
    if(cmd=="push_back"){
      int num;
      cin >> num;
      Q.push_back(num);
    }
    else if(cmd=="push_front"){
      int num;
      cin >> num;
      Q.push_front(num);
    }
    else if(cmd=="front"){
      if(Q.empty())cout<<-1<<'\n';
      else cout<<Q.front()<<'\n';
    }
    else if(cmd=="back"){
      if(Q.empty())cout<<-1<<'\n';
      else cout<<Q.back()<<'\n';
    }
    else if(cmd=="size"){
      cout<<Q.size()<<'\n';
    }
    else if(cmd=="empty"){
      cout<<Q.empty()<<'\n';
    }
    else if(cmd=="pop_front"){
      if(Q.empty())cout<<-1<<'\n';
      else{
        cout<<Q.front()<<'\n';
        Q.pop_front();
      }
    }
    else if(cmd=="pop_back"){
      if(Q.empty()) cout<<-1<<'\n';
      else{
        cout<<Q.back()<<'\n';
        Q.pop_back();
      }
    }
  }
  return 0;
}
