/*
 * author:  mimingucci
 * created: [Sat] Nov 16, 2024 19:31:05
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;
    while (q--) {
        int idx;
        cin >> idx;
        if (idx <= n) {
            cout << s[idx - 1] << " ";
            continue;
        }
        int sz = n;
        while (sz < idx)
            sz *= 2;
        int cnt = 0;
        while (idx > n) {
            sz /= 2;
            if (idx - sz > 0) {
                ++cnt;
                idx -= sz;
            }
        }
        char ans = s[idx - 1 >= 0 ? idx - 1 : n - 1];
        if (cnt % 2) {
            if (ans - 'a' >= 0 && ans - 'a' < 26) {
                ans = toupper(ans);
            } else {
                ans = tolower(ans);
            }
        }
        cout << ans << " ";
    }
    return 0;
}