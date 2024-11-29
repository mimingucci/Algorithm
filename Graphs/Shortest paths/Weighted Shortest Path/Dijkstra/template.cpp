/*
 * author:  mimingucci
 * created: [Thu] Nov 28, 2024 23:08:45
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        std::vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        vector<vector<pair<int, int>>> neighbors(n + 1);
        for (int i = 1; i <= n; i++) {
            if (i > 1)
                neighbors[i].push_back({i - 1, 0});
            neighbors[i].push_back({b[i], a[i]});
        }

        // Initially set all distances to infinity
        vector<int> dist(n + 1, INF);

        // Dijkstra's algorithm
        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        int start = 1;
        dist[start] = 0; // The shortest path from a node to itself is 0
        pq.push({0, start});

        while (!pq.empty()) {
            const auto [cdist, node] = pq.top();
            pq.pop();
            if (cdist != dist[node]) {
                continue;
            }
            for (const pair<int, int> &i : neighbors[node]) {
                // If we can reach a neighbouring node faster,
                // we update its minimum distance
                if (cdist + i.second < dist[i.first]) {
                    pq.push({dist[i.first] = cdist + i.second, i.first});
                }
            }
        }

        for (int i = 1; i <= n; i++)
            a[i] += a[i - 1];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, a[i] - dist[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}