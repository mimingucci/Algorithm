/*
 * author:  mimingucci
 * created: [Sat] Sep 27, 2025 18:59:20
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
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = i * i * i;
        if (i % 2) {
            ans -= x;
        } else {
            ans += x;
        }
    }
    cout << ans;
    return 0;
}
