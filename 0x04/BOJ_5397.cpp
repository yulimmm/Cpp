#include <iostream>
#include <string>
using namespace std;
int testCase;
int nextAddr[1000002];

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> testCase;
  while(testCase--){
    string log;
    cin >> log;
    int idxSize = log.size();
    int cur = 0, totalchar = 0;
    fill(nextAddr, nextAddr+idxSize, -1);
    for(int idx = 0; idx < idxSize; idx++){
      if(log[idx]=='>'){
        cur++;
        if(cur >= idxSize) cur = idxSize - 1;
      }
      else if(log[idx]=='<'){
        cur--;
        if(cur<0) cur = 0;
      }
      else if(log[idx]=='-'){
        //totalchar--;
      }
      else{
        nextAddr[idx] = cur;
        for(int i = 0; i < idxSize; i++){
          if(nextAddr[i]==cur) nextAddr[i] = idx;
        }
        cur++;
        totalchar++;
      }
    }
    int i = 0;
    while(totalchar--){
      int idx = 0;
      while (idx < idxSize){
        if(nextAddr[idx]==i){
          cout << log[idx];
          break;
        }
        idx++;
      }

    }
  }
  return 0;
}
