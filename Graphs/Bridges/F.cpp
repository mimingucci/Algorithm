/*
 * author:  mimingucci
 * created: [Fri] Jun 28, 2024 23:56:43
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

// link problem: https://codeforces.com/contest/1986/problem/F

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        vector<int> tin(n, -1), low(n, -1);
        int timer = 0;
        int ans = n * (n - 1) / 2;
        auto dfs = [&](auto &&self, int v, int p = -1) -> int {
            visited[v] = true;
            tin[v] = low[v] = timer++;
            int cnt = 1;
            bool parent_skipped = false;
            for (int to : adj[v]) {
                if (to == p && !parent_skipped) {
                    parent_skipped = true;
                    continue;
                }
                if (visited[to]) {
                    low[v] = min(low[v], tin[to]);
                } else {
                    int sz = self(self, to, v);
                    cnt += sz;
                    low[v] = min(low[v], low[to]);
                    if (low[to] > tin[v])
                        ans = min(ans, (sz) * (sz - 1) / 2 +
                                           (n - sz) * (n - sz - 1) / 2);
                }
            }
            return cnt;
        };
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                dfs(dfs, i);
        }
        cout << ans << '\n';
    }
    return 0;
}