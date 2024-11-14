//행렬정렬 Level D3
#include <iostream>
using namespace std;
    
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
      
  int T;
  cin >> T;
  int arr[64][64];
  for(int tc=1; tc<=T; tc++) {
    int n, cnt = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
          cin >> arr[i][j];   
      }
    }
      
    int st = n;
    bool ck = 1;
    for(int i=n-1; i>=1; i--) {
      bool tmp = (arr[0][i] == st);
      if(ck != tmp) {
        cnt++;
        ck = !ck;
      }
      st--;
    }
      
    cout << cnt << "\n";
  }
  return 0;
}
