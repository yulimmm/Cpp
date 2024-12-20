#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n,m;
string board[105];
int dist[105][105];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> board[i];
    fill(dist[i], dist[i]+m, 0);
  }
  queue<pair<int, int>>Q;
  Q.push({0,0}); dist[0][0] = 1;
  while(!Q.empty()){
    pair<int, int>current = Q.front(); Q.pop();
    int x = current.first;
    int y = current.second;
    for(int dir = 0; dir < 4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny]=='0' || dist[nx][ny]!=0) continue;
      Q.push({nx,ny}); dist[nx][ny]=dist[x][y]+1;
    }
  }
  cout<<dist[n-1][m-1];
  return 0;
}
