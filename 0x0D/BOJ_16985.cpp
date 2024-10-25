#include <iostream>
using namespace std;

bool puzzle[5][5];
//경우의 수: 순서 상관 o, 중복 x 5P4?
int minAns = 0;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin >> puzzle[i][j];
    }
  }

  while(1){

  }

  cout << minAns;

  return 0;
}
