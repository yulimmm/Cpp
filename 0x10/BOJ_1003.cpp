#include <iostream>
using namespace std;

int T;
int N[42];

int fibonacci(int n) {
  if(n == 0){
    cout<<0;
    return 0;
  } 
  else if (n == 1){
    cout<<1;
    return 1;
  }
  else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> T;

  return 0;
}
