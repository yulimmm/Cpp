#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool board[102][102];
bool via[102][102];
bool isusedPoint[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, totalIsland;

struct point{
  int x;
  int y;
};
vector<vector<point>>bridgePoints;

void printBridgeInfo()
{
  for(int islandIdx = 0; islandIdx < totalIsland; islandIdx++){
    cout<<"\n"<<islandIdx<<"번째 섬의 브릿지 가능 좌표 ";
    int totalPoints = bridgePoints[islandIdx].size();
    for(int i = 0; i < totalPoints; i++){
      cout<<"("<<bridgePoints[islandIdx][i].x<<','<<bridgePoints[islandIdx][i].y<<") ";
    }
    cout<<'\n';
  }
}

void checkWater(int islandIdx, int x, int y)
{
  if(isusedPoint[x][y]) return;
  for(int dir = 0; dir < 4; dir++){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
    if(board[nx][ny]==0){
      bridgePoints.push_back(vector<point>());
      bridgePoints[islandIdx].push_back({x, y});
      isusedPoint[x][y] = 1;
      return;
    }
  }
}

int getTotalIsland()
{
  queue<pair<int,int>>Q;
  int islandIdx = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(!board[i][j] || via[i][j]) continue;
      Q.push({i,j}); via[i][j] = 1;
      checkWater(islandIdx, i, j);
      for(int k = 0; k < n; k++)fill(isusedPoint[k],isusedPoint[k]+n,0);
      while(!Q.empty()){
        pair<int,int>cur = Q.front(); Q.pop();
        int curX = cur.first;
        int curY = cur.second;
        for(int dir = 0; dir < 4; dir++){
          int nx = curX + dx[dir];
          int ny = curY + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if(!board[nx][ny] || via[nx][ny])continue;
          Q.push({nx,ny}); via[nx][ny] = 1;
          checkWater(islandIdx, nx, ny);
        }
      }
      islandIdx++;
    }
  }
  return islandIdx;
}

int calDist(int x_1, int y_1, int x_2, int y_2)
{
  return abs(x_1 - x_2) + abs(y_1 - y_2) -1;
}

int getMinDist()
{
  //cout<<"\ngetMinDist: ";
  int minDist = 10000;
  int dist;
  for(int islandIdx = 0; islandIdx < totalIsland-1; islandIdx++){
    int totalPoints = bridgePoints[islandIdx].size();
    for(int curIdx = 0; curIdx < totalPoints; curIdx++){
      for(int nxtislandIdx = islandIdx+1; nxtislandIdx<totalIsland; nxtislandIdx++){
        int nextTotalPoints = bridgePoints[nxtislandIdx].size();
        for(int i = 0; i < nextTotalPoints; i++){
          int x_1 = bridgePoints[islandIdx][curIdx].x;
          int y_1 = bridgePoints[islandIdx][curIdx].y;
          int x_2 = bridgePoints[nxtislandIdx][i].x;
          int y_2 = bridgePoints[nxtislandIdx][i].y;
          dist = calDist(x_1, y_1, x_2, y_2);
          //cout<<dist<<' ';
          minDist = min(minDist, dist);
        }
      }
    }
  }
  //cout<<"\nminDist: "<<minDist<<'\n';
  return minDist;
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> board[i][j];
  totalIsland = getTotalIsland();
  cout << getMinDist();
  //printBridgeInfo();
  return 0;
}
