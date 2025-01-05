#include <iostream>
#include <queue>
using namespace std;
int n, testCase, ans;
int student[100002];
bool ischosen[100002];

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> testCase;
  for(int tc = 0; tc < testCase; tc++){
    cin >> n;
    ans = n;
    queue<int>Q;
    int fail = 0;
    for(int i = 0; i < n; i++) cin >> student[i];
    fill(ischosen, ischosen+n+1, 0);
    for(int studentIdx = 0; studentIdx < n; studentIdx++){
      int chosenStudent = student[studentIdx];
      if(ischosen[chosenStudent]) continue;
      Q.push(chosenStudent); ischosen[chosenStudent] = 1;
      int successNum = 0;
      while(!Q.empty()){
        int curStudent = Q.front(); Q.pop();
        int chosenStudent = student[curStudent];
        if(ischosen[chosenStudent]) continue;
        successNum++;
      }
      ans -= successNum;
    }
  }
  return 0;
}
