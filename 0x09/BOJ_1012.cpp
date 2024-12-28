#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int m,n,testcase, k; //m=가로
bool board[52][52];
bool vis[52][52];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>>Q;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> testcase;
  for(int tc = 0; tc < testcase; tc++){
    cin >> m >> n >> k;
    for(int i = 0; i < n; i++){
      fill(board[i], board[i]+m, 0);
      fill(vis[i], vis[i]+m, 0);
    }
    for(int i = 0; i < k; i++){
      int x, y;
      cin >> x >> y;
      board[x][y] = 1;
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        if(vis[i][j]==1 || board[i][j]==0)continue;
        Q.push({i,j}); vis[i][j] = 1;
        while(!Q.empty()){
          pair<int, int>cur=Q.front(); Q.pop();
          int x = cur.first;
          int y = cur.second;
          for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n)continue;
            if(vis[nx][ny]==1 || board[nx][ny]==0)continue;
            Q.push({nx,ny});
            vis[nx][ny] = 1;
          }
        }
        ans++;
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}
