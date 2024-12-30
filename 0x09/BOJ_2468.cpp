#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int board[102][102];
bool via[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ans = 1, n, threshold = 0;
queue<int>heights;
bool heightsUsed[100] = {0};

int getArea(int threshold)
{
  int area = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(via[i][j]==1 || board[i][j]<=threshold) continue;
      area++;
      queue<pair<int,int>>Q;
      Q.push({i,j}); via[i][j] = 1;
      while(!Q.empty()){
        pair<int,int>cur = Q.front(); Q.pop();
        int x = cur.first;
        int y = cur.second;
        for(int dir = 0; dir < 4; dir++){
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if(via[nx][ny] || board[nx][ny]<=threshold) continue;
          Q.push({nx,ny}); via[nx][ny]=1;
        }
      }
    }
  }
  return area;
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
      int temp = board[i][j];
      if(!heightsUsed[temp]){
        heights.push(temp);
        heightsUsed[temp] = 1;
      }
    }
  }
  int count = heights.size();
  while(count--){
    for(int i = 0; i < n; i++) fill(via[i], via[i]+n, 0);
    threshold = heights.front(); heights.pop();
    int area = getArea(threshold);
    ans = max(area, ans);
  }
  cout<<ans;
  return 0;
}
