#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool canTransform(string S, string E) {
  while (E.length() > S.length()) {
    if (E.back() == 'X') {
      E.pop_back();
    } else if (E.back() == 'Y') {
      E.pop_back();
      reverse(E.begin(), E.end());
    }
  }
  return S == E; 
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int T;
  cin >> T; 
  while (T--) {
    string S, E;
    cin >> S >> E;
    if (canTransform(S, E)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
  }
  
  return 0;
}
