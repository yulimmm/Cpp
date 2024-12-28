#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int m, n, k;
bool board[102][102];
bool via[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>>Q;
int fromX, fromY, toX, toY;
int sizeArr[10000];

void printBoard()
{
  for(int j = 0; j < n; j++){
    for(int i = 0; i < m; i++){
      cout<<board[j][i]<<' ';
    }
    cout<<'\n';
  }
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> m >> n >> k;
  for(int i = 0; i < n; i++){
    fill(board[i],board[i]+m,0);
    fill(via[i],via[i]+m,0);
  }
  for(int tc = 0; tc < k; tc++){
    cin >> fromX >> fromY >> toX >> toY;
    for(int i = fromY; i < toY; i++){
      for(int j = fromX; j <toX; j++){
        board[j][i]=1;
      }
    }
  }
  int totalArea = 0;
  for(int j = 0; j < n; j++){
    for(int i = 0; i <m; i++){
      if(board[j][i]==1 || via[j][i]==1) continue;
      Q.push({i,j}); via[j][i]=1;
      int area = 1;
      while(!Q.empty()){
        pair<int,int>cur=Q.front(); Q.pop();
        int x = cur.first;
        int y = cur.second;
        for(int dir = 0; dir < 4; dir++){
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
          if(via[ny][nx]==1 || board[ny][nx]==1) continue;
          area++;
          Q.push({nx,ny}); via[ny][nx] = 1;
        }
      }
      sizeArr[totalArea] = area;
      totalArea++;
    }
  }
  sort(sizeArr, sizeArr+totalArea);
  cout<<totalArea<<'\n';
  for(int i = 0; i < totalArea; i++) cout<<sizeArr[i]<<' ';
  //cout<<"\n---------------\n";
  //printBoard();
  return 0;
}
