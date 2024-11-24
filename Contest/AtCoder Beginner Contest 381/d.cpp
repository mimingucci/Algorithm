/*
 * author:  mimingucci
 * created: [Sat] Nov 23, 2024 22:20:26
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
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    std::vector<int> dp(n + 1, int(0));
    std::map<int, int> lst;
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            int x = i - lst[a[i]];
            if (x & 1)
                x -= 1;
            x = max(x, int(2));
            dp[i] = min(2 + dp[i - 2], x);
            lst[a[i]] = i;
        }
    }
    for (int i : dp) {
        ans = max(ans, i);
    }
    cout << ans;
    return 0;
}