#include <iostream>
using namespace std;

int student[100002];
bool ischosen[100002];
int testCase, n, ans;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> testCase;
  for(int tc = 0; tc < testCase; tc++){
    ans = 0;
    cin >> n;
    fill(ischosen, ischosen+n, 0);
    for(int i = 0; i < n; i++) cin >> student[i];
    for(int i = 0; i < n; i++){
      int num = student[i];
      if(ischosen[num]) ans++;
      else ischosen[num] = 1;
    }
    if(ans==0) cout<<0<<'\n';
    else cout<<ans+1<<'\n';
  }
  return 0;
}
