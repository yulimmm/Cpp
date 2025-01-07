#include <iostream>
#include <queue>
using namespace std;
int n, k;
int dist[200000];

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  fill(dist, dist+200000, -1);
  queue<int>Q;
  Q.push(n); dist[n] = 0;
  while(!Q.empty()){
    int cur = Q.front(); Q.pop();
    if(cur==k){
      cout<<dist[cur];
      return 0;
    }
    for(int nx : {cur-1,cur+1,cur*2}){
      if(nx < 0 || nx > 200000 || dist[nx]!=-1) continue;
      if(nx==cur*2) dist[nx] = dist[cur];
      else dist[nx] = dist[cur] + 1;
      Q.push(nx);
    }
  }
  cout<<dist[k];
  return 0;
}
