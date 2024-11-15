//방울 마술 Level D3
#include <iostream>
#include <string>
using namespace std;

int ans;
int testCase;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> testCase;
  for(int i = 1; i <= testCase; i++){
    string ss;
    int num;
    cin >> ss >> num;

    for(int k = 0; k < 3; k++){
      if(ss[k]=='o') ans = k;
    }

    while(num--){
      if(ans==0)ans=1;
      else if(ans==1)ans=0;
      else if(ans==2)ans=1;
    }

    cout<<'#'<<i<<' '<<ans<<'\n';
  }

  return 0;
}

/*
3
.o. 1
o.. 1
..o 0
*/
