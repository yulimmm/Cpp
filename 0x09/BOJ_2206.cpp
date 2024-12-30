#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string orgBoard[1002];
string tempBoard[1002];
int dist[1002][1002];
int ans = 1000000;
queue<pair<int, int>> walls;

void debugDist() {
    cout << "\n----Dist----\n";
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cout << dist[y][x];
        }
        cout << '\n';
    }
}

void printTempBoard() {
    cout << "\n----tempBoard----\n";
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cout << tempBoard[y][x];
        }
        cout << '\n';
    }
}

int getDist() {
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0][0] = 1;

    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        int x = cur.first;
        int y = cur.second;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (dist[ny][nx] > -1 || tempBoard[ny][nx] == '1') continue;
            Q.push({nx, ny});
            dist[ny][nx] = dist[y][x] + 1;
        }
    }
    return (dist[n - 1][m - 1] == -1) ? -1 : dist[n - 1][m - 1];
}

void Init(int X, int Y) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            tempBoard[y][x] = orgBoard[y][x];
            dist[y][x] = -1;
        }
    }
    if (X >= 0 && X < m && Y >= 0 && Y < n) { // 안전하게 범위 확인
        tempBoard[Y][X] = '0';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        cin >> orgBoard[y];
        for (int x = 0; x < m; x++) {
            if (orgBoard[y][x] == '1') {
                walls.push({x, y});
            }
        }
    }

    int count = walls.size();
    Init(0, 0);
    int temp = getDist();
    if (temp != -1) ans = temp;

    while (count--) {
        pair<int, int> brok = walls.front();
        walls.pop();
        Init(brok.first, brok.second);
        temp = getDist();
        if (temp != -1) ans = min(ans, temp);
    }

    if (ans == 1000000) cout << -1;
    else cout << ans;

    return 0;
}
