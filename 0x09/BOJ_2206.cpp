#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
string board[1002];
int dist[1002][1002][2];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m;

int bfs()
{
  int x, y, broke;
  queue<tuple<int,int,int>>Q;
  Q.push({0,0,0}); dist[0][0][0] = dist[0][0][1] = 1;
  while(!Q.empty()){
    tie(x, y, broke) = Q.front();
    if(x==n-1 && y==m-1) return dist[x][y][broke];
    Q.pop();
    int nextdist = dist[x][y][broke] + 1;
    for(int dir = 0; dir < 4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny]=='0' && dist[nx][ny][broke]==-1){
        dist[nx][ny][broke] = nextdist;
        Q.push({nx,ny,broke});
      }
      if(!broke && board[nx][ny]=='1' && dist[nx][ny][1]==-1){
        dist[nx][ny][1] = nextdist;
        Q.push({nx,ny,1});
      }
    }
  }
  return -1;
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> board[i];
    for(int j = 0; j < m; j++){
      dist[i][j][0] = dist[i][j][1] = -1;
    }
  }
  int ans = bfs();
  cout<<ans;
  return 0;
}
