#include <iostream>
#include <utility>
#include <queue>
using namespace std;

bool board[50][50] = {0};
bool via[50][50] = {0};
int dx[4] = {1, 0, -1, 0}; // 세로 이동(상하)
int dy[4] = {0, 1, 0, -1}; // 가로 이동(좌우)
int num, k, n, m; // m: 가로길이, n: 세로
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num;

    while (num--)
    {
        cin >> m >> n >> k;
        int x, y;

        // 각 테스트 케이스마다 배열 초기화
        for (int i = 0; i < n; i++) {
            fill(board[i], board[i] + m, 0);
            fill(via[i], via[i] + m, 0);
        }

        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            board[y][x] = 1; // y는 행(세로), x는 열(가로)
        }

        queue<pair<int, int>> Q;
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                if (board[a][b] == 0 || via[a][b]) continue;
                Q.push({a, b});
                via[a][b] = 1;
                ans++;

                // BFS 탐색
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int ny = cur.first + dx[dir]; // 세로 이동
                        int nx = cur.second + dy[dir]; // 가로 이동
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if (board[ny][nx] == 0 || via[ny][nx]) continue;
                        via[ny][nx] = 1;
                        Q.push({ny, nx});
                    }
                }
            }
        }

        cout << ans << endl;
        ans = 0;
    }

    return 0;
}
