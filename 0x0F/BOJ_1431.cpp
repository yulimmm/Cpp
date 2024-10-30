#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct GUITAR{
  string serial;
  int total_len;
  int sum = 0;
};

GUITAR guitar[50];

void findInt(char c, int i)
{
  int num = c-'0';
  if(num >= 0 && num <= 9) guitar[i].sum+=num;
  return;
}

bool compare(const GUITAR &a, const GUITAR &b)
{
  if(a.total_len != b.total_len)
    return a.total_len < b.total_len;
  if(a.sum != b.sum)
    return a.sum < b.sum;
  return a.serial < b.serial;
}

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  int N;
  cin >> N;
  for(int i = 0; i < N; i++){ 
    cin >> guitar[i].serial;
    guitar[i].total_len = guitar[i].serial.size();
    for(int j = 0; j < guitar[i].total_len; j++){
      findInt(guitar[i].serial[j], i);
    }
  }

  //우선 순위: 글자 길이 -> 숫자 넘 -> 사전순
  sort(guitar, guitar+N, compare);

  for(int i = 0; i < N; i++) {
    cout << guitar[i].serial << '\n';
  }

  return 0;
}
