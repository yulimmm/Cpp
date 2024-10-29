#include <iostream>
#include <utility>
#include <queue>
using namespace std;

char board[1000][1000];
int Fdist[1000][1000]; //불 이동 거리
int Sdist[1000][1000]; //상근이 이동 거리
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int TestCase;

void initDist(int w, int h)
{
  for(int i = 0; i < h; i++){
    fill(Fdist[i], Fdist[i]+w, 0);
    fill(Sdist[i], Sdist[i]+w, 0);
  }
  return;
}

void printDist(int w, int h)
{
  cout<<"\nFdist-------\n";
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout<<Fdist[i][j];
    }
    cout<<'\n';
  }
  cout<<"\nSdist-------\n";
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout<<Sdist[i][j];
    }
    cout<<'\n';
  }
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> TestCase;
  while(TestCase--){
    int w, h;
    cin >> w >> h;
    initDist(w, h);
    queue<pair<int,int>>FQ, SQ;
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        cin >> board[i][j];
        if(board[i][j]=='*') {FQ.push({j,i}); Fdist[i][j]++;}
        if(board[i][j]=='@') {SQ.push({j,i}); Sdist[i][j]++;}
      }
    }
    //불 이동 거리 탐색 
    while(!FQ.empty()){
      auto cur = FQ.front(); FQ.pop();
      for(int dir = 0; dir < 4; dir++){
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];
        if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
        if(board[ny][nx]=='#'||Fdist[ny][nx]!=0) continue;
        Fdist[ny][nx] = Fdist[cur.second][cur.first] + 1;
        FQ.push({nx,ny});
      }
    }
    //상근이 거리 탐색
    bool success = false;
    while(!SQ.empty()){
      auto cur = SQ.front(); SQ.pop();
      for(int dir = 0; dir < 4; dir++){
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];
        if(nx < 0 || nx >= w || ny < 0 || ny >= h){
          cout<<Sdist[cur.second][cur.first]<<'\n';
          success = true;
          break;
        }
        if(board[ny][nx]=='#' || Sdist[ny][nx]!=0) continue;
        if(Sdist[cur.second][cur.first]+1 >= Fdist[ny][nx]) continue;
        Sdist[ny][nx] = Sdist[cur.second][cur.first]+1;
        SQ.push({nx,ny});
      }
    }
    if(!success) cout<<"IMPOSSIBLE\n";
    //printDist(w, h);
  }

  return 0;
}
