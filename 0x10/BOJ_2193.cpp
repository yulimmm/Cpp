#include <iostream>
using namespace std;

long long d[100][2];
int num;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> num;
  d[1][1] = 1;
  for(int i = 2; i <= num; i++){
    d[i][0] = d[i-1][0] + d[i-1][1];
    d[i][1] = d[i-1][0];
  }
  cout<< d[num][0]+d[num][1];
  return 0;
}
