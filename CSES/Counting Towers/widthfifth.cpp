/*
 * author:  mimingucci
 * created: [Fri] Jun 21, 2024 15:21:53
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
    std::vector<std::vector<int>> dp(n + 2, std::vector<int>(32, 0));
    dp[0][31] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] += dp[i - 1][31];
        for (int j = 0; j < 31; j++) {
            std::vector<bool> bit(5, false);
            for (int x = 0; x < 5; x++) {
                if ((j >> x) && 1)
                    bit[x] = true;
            }
            int cur = 0;
            for (int x = 0; x < 5; x++) {
                if (!bit[x])
                    cur += (1 << x);
            }
            dp[i + 1][cur] += dp[i][j];
            cur = 0;
            for (int x = 0; x < 4; x++) {
                if (!bit[x] && !bit[x + 1]) {
                    cur = 0;
                    for (int y = 0; y < 5; y++) {
                        if (!bit[y] && y != x && y != x + 1) {
                            cur += (1 << y);
                        }
                    }
                    dp[i + 1][cur] += dp[i][j];
                }
            }
            cur = 0;
            for (int x = 0; x < 3; x++) {
                if (!bit[x] && !bit[x + 1]) {
                    for (int y = x + 2; y < 4; y++) {
                        if (!bit[y] && !bit[y + 1]) {
                            cur = 0;
                            for (int z = 0; z < 5; z++) {
                                if (!bit[z] && z != x && z != x + 1 && z != y &&
                                    z != y + 1)
                                    cur += (1 << z);
                            }
                            dp[i + 1][cur] += dp[i][j];
                        }
                    }
                }
            }
        }
    }
    cout << dp[n][31] + dp[n + 1][0];
    return 0;
}