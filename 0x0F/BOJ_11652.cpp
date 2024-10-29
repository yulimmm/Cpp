#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

long long mxVal =-(1ll<<62)-1;
long long mxCnt = 0;
int totalCard;
long long arr[100000];

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> totalCard;
  for(int i = 0; i < totalCard; i++){
    cin >> arr[i];
  }
  sort(arr, arr+totalCard);
  int curCnt = 1;
  for(int i = 1; i < totalCard; i++){
    if(arr[i-1]==arr[i]){
      curCnt++;
    }
    else{
      if(mxCnt < curCnt){
        mxCnt = curCnt;
        mxVal = arr[i-1];
      }
      else if(mxCnt == curCnt){
        if(mxVal > arr[i-1]) mxVal = arr[i-1];
      }
      curCnt = 1;
    }
  }

  if(mxCnt < curCnt){
    mxCnt = curCnt;
    mxVal = arr[totalCard - 1];
  }
  else if(mxCnt == curCnt){
    if(mxVal > arr[totalCard - 1]) mxVal = arr[totalCard - 1];
  }

  cout<<mxVal;
  return 0;
}
