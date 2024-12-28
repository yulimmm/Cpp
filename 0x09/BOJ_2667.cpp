#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
string board[30];
bool via[30][30];
int n, total = 0;
int arr[700];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>>Q;
int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> board[i];
    fill(via[i],via[i]+n,0);
  }
  for(int j = 0; j < n; j++){
    for(int i = 0; i < n; i++){
      if(via[j][i] || board[j][i]=='0') continue;
      Q.push({i,j}); via[j][i]=1;
      int area = 1;
      while(!Q.empty()){
        pair<int,int>cur=Q.front(); Q.pop();
        int x = cur.first;
        int y = cur.second;
        for(int dir = 0; dir < 4; dir++){
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if(board[ny][nx]=='0'||via[ny][nx]) continue;
          area++;
          Q.push({nx,ny});
          via[ny][nx] = 1;
        }
      }
      arr[total]=area;
      total++;
    }
  }
  sort(arr,arr+total);
  cout<<total<<'\n';
  for(int i = 0; i < total; i++) cout<<arr[i]<<'\n';
  return 0;
}
