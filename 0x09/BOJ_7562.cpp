#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
queue<pair<int,int>>Q;
int testCase, n;
int dist[302][302];
int fromX, fromY, toX, toY;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> testCase;
  for(int tc = 0; tc < testCase; tc++){
    cin >> n;
    for(int i = 0; i < n; i++) fill(dist[i],dist[i]+n,-1);
    cin >> fromX >> fromY;
    cin >> toX >> toY;
    Q.push({fromX, fromY}); dist[fromX][fromY] = 0;
    while(!Q.empty()){
      pair<int,int>cur=Q.front(); Q.pop();
      int x = cur.first;
      int y = cur.second;
      for(int dir = 0; dir < 8; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(dist[nx][ny]>-1) continue;
        dist[nx][ny] = dist[x][y] + 1;
        Q.push({nx,ny});
      }
    }
    if(dist[toX][toY]==-1) cout<<"fail\n";
    else cout<<dist[toX][toY]<<'\n';
  }
  return 0;
}
