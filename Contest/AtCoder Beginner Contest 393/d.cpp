/*
 * author:  mimingucci
 * created: [Sat] Feb 15, 2025 19:51:23
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
    vector<int> a;
    for (int i = 0; i < n; i++) if (s[i] == '1') a.push_back(i);
    vector<int> b;
    b.push_back(a.front());
    for (int i = 1; i < a.size(); i++) {
        b.push_back(b.back() + a[i]);
    }
    int ans = INF;
    int nn = a.size();
    auto sum = [&] (int l, int r) -> int {
        int x = r * (r + 1) / 2;
        int y = (l - 1) * l / 2;
        return x - y;
    };
    for (int pos = 0; pos <= n - a.size(); pos++) {
        auto check = [&] (int x, int y) -> bool {
            return a[x] >= y + x;
        };
        if (a[0] >= pos) {
            ans = min(ans, b.back() - sum(pos, pos + nn - 1));
        } else if (a[nn - 1] < pos + nn - 1) {
            ans = min(ans, sum(pos, pos + nn - 1) - b.back());
        } else {
            int l = 0, r = nn - 1;
            while (l + 1 < r) {
                int mid = l + r >> 1;
                if (check(mid, pos)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            int idx = r;
            if (check(l, pos)) idx = l;
            ans = min(ans, sum(pos, pos + idx - 1) - b[idx - 1] + b.back() - b[idx - 1] - sum(pos + idx, pos + nn - 1));
        }
    }
    cout << ans;
    return 0;
}

