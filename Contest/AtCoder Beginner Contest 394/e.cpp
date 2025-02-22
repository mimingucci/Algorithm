/*
 * author:  mimingucci
 * created: [Sat] Feb 22, 2025 19:36:29
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    char a[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> adj(n + 1), rev_adj(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != '-') {
                adj[i].push_back(j);
                rev_adj[j].push_back(i);
            }
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    deque<array<int, 2>> q;
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
        q.push_back({i, i});
        vis[i][i] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && a[i][j] != '-') {
                dp[i][j] = 1;
                q.push_back({i, j});
                vis[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();
        for (int i : adj[y]) {
            for (int j : rev_adj[x]) {
                if (a[j][x] == a[y][i]) {
                    dp[j][i] = min(dp[j][i], dp[x][y] + 2);
                    if (!vis[j][i]) {
                        q.push_back({j, i});
                        vis[j][i] = true;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] == INF) {
                cout << "-1 ";
            } else {
                cout << dp[i][j] << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}
