#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};
int board[300][300];
int dist[300][300] = {0};
int testCase;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> testCase;
  while(testCase--){
    int l;
    cin >> l;
    for(int i = 0; i < l; i++) fill(dist[i], dist[i]+l, 0);
    queue<pair<int, int>>Q;
    int start_x, start_y;
    cin >> start_x >> start_y;
    Q.push({start_x,start_y});
    dist[start_x][start_y]++;
    int arrive_x, arrive_y;
    cin >> arrive_x >> arrive_y;
    while(!Q.empty()){
      auto cur = Q.front(); Q.pop();
      for(int dir = 0; dir < 8; dir++){
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];
        if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
        if(dist[nx][ny]!=0) continue;
        dist[nx][ny] = dist[cur.first][cur.second] + 1;
        if(nx == arrive_x && ny == arrive_y) break;
        Q.push({nx,ny});
      }
    }
    cout<<dist[arrive_x][arrive_y]-1<<'\n';
  }
  return 0;
}
