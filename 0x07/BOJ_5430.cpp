#include <iostream>
#include <deque>
#include <string>
#include <sstream> // For parsing numbers
using namespace std;

int testCase;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> testCase;
    
    while (testCase--) {
        string cmd, num;
        int total;
        cin >> cmd >> total >> num;

        deque<int> dq;
        bool front = true, err = false;

        // 배열 파싱
        num = num.substr(1, num.size() - 2); // Remove brackets '[' and ']'
        stringstream ss(num);
        string value;
        while (getline(ss, value, ',')) {
            if (!value.empty()) {
                dq.push_back(stoi(value)); // Convert string to integer
            }
        }

        // 명령어 처리
        for (char c : cmd) {
            if (c == 'R') {
                front = !front; // Toggle direction
            } else if (c == 'D') {
                if (dq.empty()) {
                    cout << "error\n";
                    err = true;
                    break;
                }
                if (front) dq.pop_front();
                else dq.pop_back();
            }
        }

        if (err) continue;

        // 출력
        cout << "[";
        if (front) {
            for (size_t i = 0; i < dq.size(); ++i) {
                cout << dq[i];
                if (i < dq.size() - 1) cout << ",";
            }
        } else {
            for (size_t i = dq.size(); i > 0; --i) {
                cout << dq[i - 1];
                if (i > 1) cout << ",";
            }
        }
        cout << "]\n";
    }

    return 0;
}
