#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int board[102][102][102];
int dist[102][102][102];
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};
struct XYZ{
  int x;
  int y;
  int z;
};
int m,n,h,ans=0;
queue<XYZ>Q;

void printDist()
{
  for(int k = 0; k < h; k++){
    for(int j = 0; j < n; j++){
      for(int i = 0; i < m; i++){
        cout<<dist[k][j][i];
      }
      cout<<'\n';
    }
    cout<<'\n';
  }
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> m >> n >> h;
  bool pass = 1;
  for(int k = 0; k < h; k++){
    for(int j = 0; j < n; j++){
      for(int i = 0; i < m; i++) {
        cin >> board[k][j][i];
        dist[k][j][i] = -1;
        if(board[k][j][i]==1){
          XYZ xyz = {i,j,k};
          Q.push(xyz);
          dist[k][j][i] = 0;
        }
        else if(board[k][j][i]==-1) dist[k][j][i] = -2;
        else if(board[k][j][i]==0 && pass==1) pass = 0;
      }
    }
  }
  if(pass){
    cout<<0;
    return 0;
  }
  while(!Q.empty()){
    XYZ xyz = Q.front(); Q.pop();
    int x = xyz.x;
    int y = xyz.y;
    int z = xyz.z;
    for(int dir = 0; dir < 6; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      int nz = z + dz[dir];
      if(nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
      if(dist[nz][ny][nx]>-1 || board[nz][ny][nx]!=0) continue;
      dist[nz][ny][nx] = dist[z][y][x] + 1;
      xyz = {nx,ny,nz};
      Q.push(xyz);
      ans = max(ans, dist[nz][ny][nx]);
    }
  }
  bool success = 1;
  for(int k = 0; k < h; k++){
    for(int j = 0; j < n; j++){
      for(int i = 0; i < m; i++){
        if(dist[k][j][i]==-1) success = 0;
      }
    }
  }
  if(success) cout << ans;
  else cout<<-1;
  //cout<<'\n';
  //printDist();
  return 0;
}
