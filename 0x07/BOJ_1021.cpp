#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  deque<int>DQ;
  int qsize, total, ans = 0;
  cin >> qsize >> total;
  for(int i = 1; i <= qsize; i++) DQ.push_back(i);
  while(total--){
    int num;
    cin >> num;
    int idx = find(DQ.begin(), DQ.end(), num) - DQ.begin();
    while(DQ.front()!=num){
      if(idx < DQ.size()-idx){
        DQ.push_back(DQ.front());
        DQ.pop_front();
      }
      else{
        DQ.push_front(DQ.back());
        DQ.pop_back();
      }
      ans++;
    }
    DQ.pop_front();
  }
  cout << ans;
  return 0;
}
