#include <iostream>
#include <queue>
#include <utility>
using namespace std;
string board[102];
bool vis[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;
queue<pair<int,int>>Q;

void visInit()
{
  for(int i = 0; i < n; i++) fill(vis[i],vis[i]+n,0);
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  visInit();
  for(int i = 0; i < n; i++) cin >> board[i];
  int ans1 = 0, ans2 = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(vis[i][j]==1) continue;
      Q.push({i,j});
      while(!Q.empty()){
        pair<int,int>cur=Q.front(); Q.pop();
        int curX = cur.first;
        int curY = cur.second;
        for(int dir = 0; dir < 4; dir++){
          int nx = curX + dx[dir];
          int ny = curY + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
          if(vis[nx][ny]==1 || board[nx][ny]!=board[curX][curY])continue;
          Q.push({nx,ny}); vis[nx][ny] = 1;
        }
      }
      ans1++;
    }
  }
  cout<<ans1<<' ';
  visInit();
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(vis[i][j]==1) continue;
      Q.push({i,j});
      while(!Q.empty()){
        pair<int,int>cur=Q.front(); Q.pop();
        int curX = cur.first;
        int curY = cur.second;
        for(int dir = 0; dir < 4; dir++){
          int nx = curX + dx[dir];
          int ny = curY + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
          if(vis[nx][ny]==1)continue;
          if(board[curX][curY]=='B' && board[nx][ny]!='B')continue;
          if(board[curX][curY]!='B' && board[nx][ny]=='B')continue;
          Q.push({nx,ny}); vis[nx][ny] = 1;
        }
      }
      ans2++;
    }
  }
  cout<<ans2;
  return 0;
}
