/*
 * author:  mimingucci
 * created: [Sat] Sep 27, 2025 20:02:43
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 5000;
const int MOD = 998244353; // 1e9+7

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc, p;
    cin >> tc >> p;
    vector<vector<int>> dp(5001, vector<int>(5001, 0));
    for (int i = 0; i <= MAXN; i++) {
        dp[i][0] = 1;
        if (i <= MAXN) {
            dp[i][i] = 1;
        }
    }

    for (int i = 0; i <= MAXN; i++) {
        for (int j = 1; j <= min(i, MAXN); j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % p;
        }
    }
    while (tc--) {
        int n;
        cin >> n;
        std::vector<int> a(n);
        int sz = 0;
        for (int &i : a) cin >> i;
        for (int i : a) sz += i;
        int ans = 1;
        for (int i : a) {
            // cout << sz << " - " << i << '\n';
            ans = (ans * dp[sz][i]) % p;
            sz -= i;
        }
        cout << ans << '\n';
    }    
    return 0;
}
