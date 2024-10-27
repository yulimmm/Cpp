#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int board[1000][1000];
int dist[1000][1000];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;

void printdist()
{
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cout<<dist[i][j];
    }
    cout<<'\n';
  }
}

void printboard()
{
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cout<<board[i][j];
    }
    cout<<'\n';
  }
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) fill(dist[i], dist[i]+n, -1);
  queue<pair<int, int>>Q;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
      if(board[i][j]==1) {
        Q.push({i,j});
        dist[i][j] = 0;
      }
      if(board[i][j]==-1){
        dist[i][j]=-2;
      }
    }
  }
  //printdist();
  while(!Q.empty()){
    pair<int, int>cur = Q.front(); Q.pop();
    for(int i = 0; i < 4; i++){
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
      if(dist[nx][ny]!=-1 || board[nx][ny]==-1) continue;
      dist[nx][ny] = dist[cur.first][cur.second] + 1;
      Q.push({nx,ny});
    }
  }
  int ans = 0;
  bool result = true;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      ans = max(ans, dist[i][j]);
      if(dist[i][j]==-1) result = false;
    }
  }
  //printdist();
  //cout<<"\n-------------\n";
  //printboard();
  if(!result) cout<<-1;
  else cout<<ans;
  return 0;
}
