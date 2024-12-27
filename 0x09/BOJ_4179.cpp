#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

string board[1002];
int r, c; //r행
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int fdist[1002][1002];
int jdist[1002][1002];
queue<pair<int,int>>FQ;
queue<pair<int,int>>JQ;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> r >> c;
  for(int i = 0; i < r; i++){
    fill(fdist[i],fdist[i]+c,-1);
    fill(jdist[i],jdist[i]+c,-1);
  }
  for(int i = 0; i < r; i++){
    cin >> board[i];
    for(int j = 0; j < c; j++){
      if(board[i][j]=='F'){
        FQ.push({i,j});
        fdist[i][j]=0;
      }
      else if(board[i][j]=='J'){
        JQ.push({i,j});
        jdist[i][j]=0;
      }
    }
  }
  while(!FQ.empty()){
    pair<int,int>current = FQ.front(); FQ.pop();
    int x = current.first;
    int y = current.second;
    for(int dir = 0; dir < 4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if(board[nx][ny]!='.'|| fdist[nx][ny] > -1) continue;
      fdist[nx][ny] = fdist[x][y] + 1;
      FQ.push({nx,ny});
    }
  }
  while(!JQ.empty()){
    pair<int,int>current = JQ.front(); JQ.pop();
    int x = current.first;
    int y = current.second;
    for(int dir = 0; dir < 4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 || nx >= r || ny < 0 || ny >= c){
        cout << jdist[x][y]+1;
        return 0;
      }
      if(board[nx][ny] != '.' || jdist[nx][ny] > -1) continue;
      if(fdist[nx][ny] != -1 && jdist[x][y] + 1 >= fdist[nx][ny]) continue;
      jdist[nx][ny] = jdist[x][y] + 1;
      JQ.push({nx,ny});
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}
