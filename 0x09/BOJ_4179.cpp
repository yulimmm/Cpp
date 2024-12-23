#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

string board[1002];
int r, c; //r=행
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int distF[1002][1002];
int distJ[1002][1002];
int mxF = 0, mxJ = 0;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> r >> c;
  queue<pair<int, int>>jQ;
  queue<pair<int, int>>fQ;
  for(int i = 0; i < c; i++){
    fill(distF[i],distF[i]+r,0);
    fill(distJ[i],distJ[i]+r,0);
  }
  for(int i = 0; i < c; i++){
    cin >> board[i];
    for(int k = 0; k < r; k++){
      if(board[i][k]=='J') {
        jQ.push({i,k});
        distJ[i][k] = 1;
      }
      if(board[i][k]=='F'){
        fQ.push({i,k});
        distF[i][k] = 1;
      }
    }
  }

  while(!jQ.empty()){
    pair<int, int>current = jQ.front(); jQ.pop();
    int x = current.first;
    int y = current.second;
    for(int dir = 0; dir < 4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || nx >= r || ny < 0 || ny > c) continue;
      if(board[nx][ny]!='.' || distJ[nx][ny] > 0) continue;
      distJ[nx][ny] = distJ[x][y] + 1;
      jQ.push({nx,ny});
    }
  }

  while(!fQ.empty()){
    pair<int, int>current = fQ.front(); fQ.pop();
    int x = current.first;
    int y = current.second;
    for(int dir = 0; dir < 4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || nx >= r || ny < 0 || ny > c) continue;
      if(board[nx][ny]!='.' || distF[nx][ny] > 0) continue;
      distF[nx][ny] = distF[x][y] + 1;
      fQ.push({nx,ny});
    }
  }

  bool success = 0;

  for(int i = 0; i < r; i++){
    if(distF[r][0]<distJ[r][0] && board[r][0]=='.') success = 1;
  }


  return 0;
}
