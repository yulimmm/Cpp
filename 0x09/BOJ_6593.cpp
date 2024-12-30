#include <iostream>
#include <queue>
using namespace std;
string board[30][30];
int dist[33][33][33];
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};
int l,r,c; //l: 층 r: 행 c: 열
struct XYZ{
  int x;
  int y;
  int z;
};
XYZ Start, End;

int getSec()
{
  int sec;
  queue<XYZ>Q;
  for(int i = 0; i < l; i++){
    for(int j = 0; j < r; j++){
      cin >> board[i][j];
      for(int k = 0; k < c; k++){
        if(board[i][j][k]=='S'){
          Start = {k, j, i};
          Q.push(Start);
          dist[i][j][k] = 0;
        }
        else if(board[i][j][k]=='E'){
          End = {k, j, i};
        }
      }
    }
  }
  while(!Q.empty()){
    XYZ cur = Q.front(); Q.pop();
    int x = cur.x;
    int y = cur.y;
    int z = cur.z;
    for(int dir = 0; dir < 6; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      int nz = z + dz[dir];
      if(nx < 0 || nx >= c || ny < 0 || ny >= r || nz < 0 || nz >= l) continue;
      if(dist[nz][ny][nx]>-1 || board[nz][ny][nx]=='#') continue;
      dist[nz][ny][nx] = dist[z][y][x] + 1;
      Q.push({nx, ny, nz});
    }
  }
  sec = dist[End.z][End.y][End.x];
  return sec;
}

void initDist()
{
  for(int i = 0; i < l; i++){
    for(int j = 0; j < r; j++){
      fill(dist[i][j], dist[i][j]+c, -1);
    }
  }
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  while(1)
  {
    cin >> l >> r >> c;
    if(l==0 && r==0 && c==0) break;
    initDist();
    int sec = getSec();
    if(sec==-1) cout << "Trapped!\n";
    else cout<<"Escaped in "<<sec<<" minute(s).\n";
  }
  return 0;
}
