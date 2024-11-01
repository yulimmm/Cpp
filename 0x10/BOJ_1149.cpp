#include <iostream>
using namespace std;

int rgb[1000][3];
int N;
int d[1000][3];

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  for(int i = 1; i <= N; i++){
    for(int j = 0; j < 3; j++){
      cin >> rgb[i][j];
    }
  }
  //초기값
  d[1][0] = rgb[1][0];
  d[1][1] = rgb[1][1];
  d[1][2] = rgb[1][2];
  //점화식
  for(int i = 2; i <= N; i++){
    d[i][0] = min(d[i-1][1], d[i-1][2]) + rgb[i][0];
    d[i][1] = min(d[i-1][0], d[i-1][2]) + rgb[i][1];
    d[i][2] = min(d[i-1][0], d[i-1][1]) + rgb[i][2];
  }
  int mind = min(d[N][0],d[N][1]);
  cout << min(mind, d[N][2]);

  return 0;
}
