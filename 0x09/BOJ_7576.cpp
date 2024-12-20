#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n,m;
int board[1000][1000];
int dist[1000][1000];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int mxAns = 0;

void debug()
{
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cout<<dist[i][j];
    }
    cout<<'\n';
  }
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  queue<pair<int,int>>Q;
  for(int j = 0; j < m; j++){
    for(int i = 0; i < n; i++){
      cin >> board[j][i];
      if(board[j][i]==1) Q.push({i,j});
      dist[j][i] = board[j][i];
    }
  }
  //debug();
  while(!Q.empty()){
    pair<int,int>current = Q.front(); Q.pop();
    int x = current.first;
    int y = current.second;
    for(int dir = 0; dir < 4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[ny][nx]==-1 || dist[ny][nx] > 0) continue;
      Q.push({nx,ny}); dist[ny][nx] = dist[y][x] + 1;
      mxAns = max(mxAns, dist[ny][nx]);
    }
  }
  bool success = 1;
  for(int j = 0; j < m; j++){
    for(int i = 0; i < n; i++){
      if(dist[j][i]==0) success = 0;
    }
  }
  if(success) {
    if(mxAns == 0) cout<<0;
    else cout<<mxAns-1;
  }
  else cout<<-1;
  //cout<<'\n';
  //debug();
  return 0;
}
