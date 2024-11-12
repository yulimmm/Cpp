//홀수만 더하기. Level D1
#include<iostream>
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, x;
	freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
    cout<<'#'<<test_case<<' ';
    int sum = 0;
    for(int i = 0; i<10; i++){
      cin >> x;
      if(x%2!=0){
        sum+=x;
      }
    }
    cout<<sum<<'\n';
	}
	return 0;
}
