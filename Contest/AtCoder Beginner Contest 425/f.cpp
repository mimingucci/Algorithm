/*
 * author:  mimingucci
 * created: [Sat] Sep 27, 2025 20:52:44
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
    string s;
    cin >> s;
    std::vector<int> dp(int(1 << n), int(0));
    dp[int(1 << n) - 1] = 1;
    for (int i = int(1 << n) - 1; i >= 0; i--) {
        char pre = '!';
        for (int bit = 0; bit < n; bit++) {
            if ((i >> bit) & 1) {
                if (pre != s[bit]) {
                    dp[i ^ (1 << bit)] = (dp[i ^ (1 << bit)] + dp[i]) % MOD;
                }
                pre = s[bit];
            }
        }
    }
    cout << dp[0];
    return 0;
}
