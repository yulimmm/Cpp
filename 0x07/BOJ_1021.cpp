#include <iostream>
#include <cmath>
using namespace std;
bool ispiecked[52];
int Front, End, qsize, total;
int ans = 0;

int alreadyPickedCheck()
{

}

void rangeCheck()
{
  if(Front < 1)Front = 1;
  if(Front > qsize) Front = qsize;
  if(End < 1) End = 1;
  if(End > qsize) End = qsize;
}

int judgement(int num)
{
  int count = 0;
  if(num==Front) {
    ispiecked[num] = 1;
    Front = num+1;
    End = Front -1
  }
  else if(abs(num-Front) > abs(num-End)){ //왼쪽 이동
    count = abs(num-End) - alreadyPickedCheck();
    Front = num-1;
    End = Front + 1;
    rangeCheck();
    ispiecked[num] = 1;
  }
  else{ //오른쪽 이동

  }
  return count;
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> qsize >> total;
  Front = 1; 
  End = qsize;
  while(total--){
    int num;
    cin >> num;
    ans += judgement(num);
  }
  cout<<ans;
  return 0;
}
