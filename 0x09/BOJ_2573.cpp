#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[302][302];
int tempBoard[302][302];
bool isused[302][302];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m, ans = 0;

void melting(int i, int j)
{
  int waterNum = 0;
  for(int dir = 0; dir < 4; dir++){
    int nx = i + dx[dir];
    int ny = j + dy[dir];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if(board[nx][ny]==0) waterNum++;
  }
  tempBoard[i][j] = board[i][j] - waterNum;
  if(tempBoard[i][j] < 0) tempBoard[i][j] = 0;
  //cout<<"\n("<<i<<","<<j<<") 근처 바다 수: "<<waterNum<<'\n';
}

bool groupChecking()
{
  int totalGroup = 0;
  queue<pair<int,int>>Q;
  for(int i = 0; i < n; i++) fill(isused[i], isused[i]+m, 0);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(totalGroup >= 2) return 1;
      if(board[i][j]==0 || isused[i][j]) continue;
      Q.push({i,j}); isused[i][j] = 1;
      totalGroup++;
      while(!Q.empty()){
        pair<int, int>cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if(board[nx][ny]==0 || isused[nx][ny]) continue;
          Q.push({nx, ny}); isused[nx][ny] = 1;
        }
      }
    }
  }
  return 0;
}

bool isZero()
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(board[i][j]!=0) return 0;
  return 1;
}

void printBoard()
{
  cout<<"\n----print Board----\n";
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout<<board[i][j] <<' ';
    }
    cout<<'\n';
  }
}

void printTempBoard()
{
  cout<<"\n----print temp board----\n";
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout<<tempBoard[i][j] <<' ';
    }
    cout<<'\n';
  }
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> board[i][j];

  while(1){
    if(isZero()){cout<<0; return 0;}
    ans++;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(board[i][j]!=0) melting(i, j);
        else tempBoard[i][j] = 0;
      }
    }
    //printTempBoard();
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        board[i][j] = tempBoard[i][j];
    //printBoard();
    if(groupChecking()) break;
  }
  cout<<ans;
  return 0;
}
