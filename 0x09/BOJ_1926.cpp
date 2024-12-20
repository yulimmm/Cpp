#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int n,m;
int board[505][505];
bool vis[505][505] = {0};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int maxArea = 0, num = 0;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
    }
  }

  queue<pair<int, int>>Q;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int area = 1;
      if(vis[i][j]==1 || board[i][j]==0) continue;
      Q.push({i,j}); vis[i][j] = 1;
      while(!Q.empty()){
        pair<int, int>current = Q.front(); Q.pop();
        int x = current.first;
        int y = current.second;
        for(int dir = 0; dir < 4; dir++){
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny > m) continue;
          if(vis[nx][ny]==1 || board[nx][ny]==0) continue;
          Q.push({nx,ny}); vis[nx][ny] = 1;
          area++;
        }
      }
      num++;
      maxArea = max(area, maxArea);
    }
  }
  cout<<num<<'\n'<<maxArea;
  return 0;
}
