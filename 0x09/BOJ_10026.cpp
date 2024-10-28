#include <iostream>
#include <utility>
#include <queue>
#include <string>
using namespace std;

string board[100];
bool via[100][100] = {0};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, cnt;
queue<pair<int,int>>Q;

void bfs(int i, int j)
{
  cnt++;
  while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if(via[nx][ny] || board[i][j]!=board[nx][ny]) continue;
      via[nx][ny] = 1;
      Q.push({nx,ny});
    }
  }
}

int area()
{
  cnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(!via[i][j]){
        Q.push({i,j});
        via[i][j] = 1;
        bfs(i,j);
      }
    }
  }
  return cnt;
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin>>board[i];
  cout << area();
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(board[i][j]=='G')
        board[i][j] = 'R';
    }
  }
  for(int i = 0; i < n; i++) fill(via[i], via[i]+n, 0);
  cout<<' '<<area();

  return 0;
}
