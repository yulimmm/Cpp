#include <iostream>
#include <utility>
#include <queue>
#include <array>
#include <algorithm>
using namespace std;

int board[100][100][100];
int dist[100][100][100] = {0};
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  int X, Y, Z;
  cin >> X >> Y >> Z;
  queue<array<int,3>>Q;
  for(int z = 0; z < Z; z++){
    for(int y = 0; y < Y; y++){
      for(int x = 0; x < X; x++){
        cin >> board[z][y][x];
        if(board[z][y][x] == 1) {Q.push({x,y,z}); dist[z][y][x]++;}
        if(board[z][y][x] == -1) dist[z][y][x] = -1;
      }
    }
  }

  int mn = 0;

  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 6; dir++){
      int nx = cur[0] + dx[dir];
      int ny = cur[1] + dy[dir];
      int nz = cur[2] + dz[dir];
      if(nx < 0 || nx >= X || ny < 0 || ny >= Y || nz < 0 || nz >= Z) continue;
      if(dist[nz][ny][nx]!=0 || board[nz][ny][nx]==-1) continue;
      dist[nz][ny][nx] = dist[cur[2]][cur[1]][cur[0]]+1;
      Q.push({nx,ny,nz});
      mn = max(mn, dist[nz][ny][nx]);
    }
  }

  bool sucess = true;

  //cout<<"result===============\n";
  for(int z = 0; z < Z; z++){
    for(int y = 0; y < Y; y++){
      for(int x = 0; x < X; x++){
        if(dist[z][y][x]==0) sucess = false;
        //cout<<dist[z][y][x];
      }
      //cout<<endl;
    }
    //cout<<endl;
  }
  if(sucess){
    if(mn==0) cout<<0;
    else cout<<mn-1;
  }
  else cout<<-1;

  return 0;
}
