#include <iostream>
#include <queue>
using namespace std;
int f,s,g,u,d;
int dist[1000002];
queue<int>Q;

void printDist()
{
  cout<<"\n------\n";
  for(int i = 0; i < f; i++) cout<<dist[i]<<' ';
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> f >> s >> g >> u >> d;
  fill(dist, dist+f, -1);
  Q.push(s-1); dist[s-1] = 0;
  while(!Q.empty()){
    int cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 2; dir++){
      int nx;
      if(dir == 0) nx = cur + u;
      else nx = cur + d * (-1);
      if(nx < 0 || nx >= f) continue;
      if(dist[nx]>-1) continue;
      dist[nx] = dist[cur] + 1;
      Q.push(nx);  
    }
  }
  int result = dist[g-1];
  if(result==-1) cout<<"use the stairs";
  else cout << result;
  //printDist();
  return 0;
}
