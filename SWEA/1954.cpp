#include <iostream>
using namespace std;
int board[12][12];

int right(int x, int y, int total, int start)
{
  for(int i = x; i < total; i++){
    board[y][x] = start++;
  }
  return start;
}

int down(int x, int y, int total, int start)
{
  
}

int main()
{
  int testCase;
  cin >> testCase;
  for(int tc = 1; tc <= testCase; tc++){
    cout<<"#"<<tc<<'\n';
    int num;
    cin >> num;
    while(1){
      int nxt = right(0,0,num,1);
      nxt = 
    }
  }
}
