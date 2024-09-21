/*
 * author:  mimingucci
 * created: [Sat] Sep 21, 2024 19:23:30
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    std::vector<int> a(n);
    for (int &i : a)
        cin >> i;
    std::vector<int> min_idx(MAXN, int(n));
    std::vector<int> sz(n + 1, int(0));
    std::vector<int> cur;
    for (int i = n - 1; i >= 0; i--) {
        while (!cur.empty() && a[cur.back()] < a[i]) {
            cur.pop_back();
        }
        if (!cur.empty()) {
            min_idx[i] = cur.back();
        }
        cur.push_back(i);
    }
    std::vector<int> ans(n, int(1));
    ans[n - 1] = 0;
    sz[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        ans[i] = sz[i + 1];
        sz[i] = sz[min_idx[i]] + 1;
    }
    for (int i : ans)
        cout << i << " ";
    return 0;
}