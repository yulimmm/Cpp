#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

string board[1002];
int r, c; //r: 행 c: 열
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int fdist[1002][1002];
int jdist[1002][1002];
queue<pair<int, int>>QF;
queue<pair<int, int>>QJ;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> r >> c;
  for(int i = 0; i < c; i++){ //init
    fill(fdist[i], fdist[i]+r, -1);
    fill(jdist[i], jdist[i]+r, -1);
  }
  for(int i = 0; i < c; i++){
    cin >> board[i];
    for(int j = 0; j < r; j++){
      if(board[i][j]=='F') {
        QF.push({i,j});
        fdist[i][j] = 0;
      }
      else if(board[i][j]=='J') {
        QJ.push({i,j});
        jdist[i][j] = 0;
      }
    }
  }
  while(!QJ.empty()){
    pair<int, int>current = QJ.front(); QJ.pop();
    int x = current.first;
    int y = current.second;
    for(int dir = 0; dir < 4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if(board[nx][ny]!='.' || jdist[nx][ny]>-1) continue;
      QJ.push({nx,ny});
      jdist[nx][ny] = jdist[x][y] + 1;
    }
  }
  while(!QF.empty()){
    pair<int, int>current = QF.front(); QF.pop();
    int x = current.first;
    int y = current.second;
    for(int dir = 0; dir < 4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if(board[nx][ny]!='.' || fdist[nx][ny]>-1) continue;
      QJ.push({nx,ny});
      fdist[nx][ny] = fdist[x][y] + 1;
    }
  }
  int ans = 1005;
  bool success = 0;
  for(int i = 0; i < r; i++){
    if(jdist[i][0]>-1 && jdist[i][0] < fdist[i][0]){ 
      ans = min(ans, jdist[i][0]);
      success = 1;
    }
  }
  return 0;
}
