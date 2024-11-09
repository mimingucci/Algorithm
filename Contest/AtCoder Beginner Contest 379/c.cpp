/*
 * author:  mimingucci
 * created: [Sat] Nov 09, 2024 19:08:48
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    std::vector<int> x(m), a(m);
    for (int &i : x)
        cin >> i;
    for (int &i : a)
        cin >> i;
    std::vector<pair<int, int>> v;
    for (int i = 0; i < m; i++)
        v.push_back({x[i], a[i]});
    sort(begin(v), end(v));
    int ans = 0;
    int cur = n;
    auto calc = [&](int x) -> int {
        if (x <= 0)
            return 0;
        return (x * (x + 1)) / 2;
    };
    for (int i = m - 1; i >= 0; i--) {
        int minn = cur - v[i].second + 1;
        if (minn < v[i].first) {
            ans = -1;
            break;
        }
        ans += (minn - v[i].first) * v[i].second;
        ans += calc(v[i].second - 1);
        cur = cur - v[i].second;
    }
    if (cur != 0)
        ans = -1;
    cout << ans;
    return 0;
}