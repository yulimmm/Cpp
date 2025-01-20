#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int n, l, mn = 100000001;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> l;
  deque<int>dq;
  while(n--){
    int num;
    cin >> num;
    dq.push_back(num);
    mn = min(mn, num);
    if(dq.size()>l){
      int curmn = dq.front();
      dq.pop_front();
      if(curmn==mn){
        mn = dq[0];
        for(int i = 1; i < l; i++){
          mn = min(mn,dq[i]);
        }
      }
    }
    cout<<mn<<' ';
  }
  return 0;
}
