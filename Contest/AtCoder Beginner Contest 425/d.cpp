/*
 * author:  mimingucci
 * created: [Sat] Sep 27, 2025 19:38:22
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int> dirX({1, -1, 0, 0});
    vector<int> dirY({0, 0, -1, 1});
    int n, m;
    cin >> n >> m;
    std::vector<std::vector<int>> board(n + 1, vector<int> (m + 1));
    queue<pair<int, int>> cur;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            if (x == '#') {
                board[i][j] = 1;
                cur.push({i, j});
            } else {
                board[i][j] = 0;
            }
        }
    }
    std::vector<pair<int, int>> temp;;
    while (!cur.empty()) {
        while (!cur.empty()) {
            auto &[x, y] = cur.front();
            cur.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dirX[i];
                int ny = y + dirY[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (board[nx][ny]) continue;
                int cnt = 0;
                for (int j = 0; j < 4; j++) {
                    int nnx = nx + dirX[j];
                    int nny = ny + dirY[j];
                    if (nnx < 1 || nnx > n || nny < 1 || nny > m) continue;
                    if (board[nnx][nny]) cnt++;
                }
                if (cnt == 1) temp.push_back({nx, ny});
            }
        }
        while (!temp.empty()) {
            auto &[x, y] = temp.back();
            temp.pop_back();
            cur.push({x, y});
            board[x][y] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j]) ans++;
        }
    }
    cout << ans;
    return 0;
}
