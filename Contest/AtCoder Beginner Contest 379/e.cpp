/*
 * author:  mimingucci
 * created: [Sat] Nov 09, 2024 20:47:18
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
    string s;
    cin >> s;
    deque<int> ans;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur += (s[i] - '0') * (i + 1);
        ans.push_back(cur);
    }
    for (int i = n - 1; i > 0; i--) {
        ans[i - 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    while (ans[0] >= 10) {
        ans.push_front(ans[0] / 10);
        ans[1] %= 10;
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
    cout << '\n';
    return 0;
}