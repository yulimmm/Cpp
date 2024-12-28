#include <iostream>
#include <queue>
using namespace std;
int n, k;
int dist[1000001];
int dx[2] = {-1,1};
queue<int>Q;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  fill(dist, dist+1000000,-1);
  Q.push(n); dist[n] = 0;
  while(!Q.empty()){
    int current = Q.front(); Q.pop();
    for(int dir = 0; dir < 3; dir++){
      int nx;
      if(dir==2) nx = current*2;
      else nx = current + dx[dir];
      if(nx < 0 || nx > 1000000) continue;
      if(dist[nx]>=0) continue;
      Q.push(nx);
      dist[nx] = dist[current] + 1;
    }
  }
  cout<<dist[k];
  //printdist();
  return 0;
}
