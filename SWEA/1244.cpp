//최대 상금 Level D3
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct value{
  int val;
  int index;
};

bool compar(const value &a, const value &b)
{
  if(a.val == b.val){
    if(a.index > b.index) return true;
  }
  if(a.val > b.val) return true;
  return false;
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  int TestCase;
  string num;
  int count;
  cin >> TestCase;
  for(int i = 1; i <= TestCase; i++){
    cin >> num >> count;
    int orig[10];
    value arr[10];
    for(int k = 0; k < num.size(); k++){
      orig[k] = num[k]-'0';
      arr[k].val = num[k]-'0';
      arr[k].index = k;
    }
    sort(arr, arr+num.size(), compar);
    int idx = 0;
    while(count!=0){
      if(orig[idx]<=arr[idx].val){
        swap(orig[idx], orig[arr[idx].index]);
        count--;
      }
      idx++;
    }

    cout<<'#'<<i<<' ';
    for(int k = 0; k < num.size(); k++){
      cout<<orig[k];
    }
    cout<<'\n';
  }

  return 0;
}
