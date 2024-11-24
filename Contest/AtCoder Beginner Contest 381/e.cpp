/*
 * author:  mimingucci
 * created: [Sun] Nov 24, 2024 00:21:02
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    std::vector<int> a, b, c;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            a.push_back(i);
        if (s[i] == '2')
            b.push_back(i);
        if (s[i] == '/')
            c.push_back(i);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        int L = 0, R = n;
        while (R - L > 1) {
            int M = (L + R) / 2;
            bool ok = false;
            int s = lower_bound(begin(a), end(a), l) - a.begin();
            if (s + M - 1 < a.size() && a[s + M - 1] < r) {
                int t = lower_bound(begin(c), end(c), a[s + M - 1]) - c.begin();
                if (t < c.size() && c[t] < r) {
                    int u = lower_bound(begin(b), end(b), c[t]) - b.begin();
                    if (u + M - 1 < b.size() && b[u + M - 1] < r)
                        ok = true;
                }
            }
            if (ok)
                L = M;
            else
                R = M;
        }
        if (L) {
            cout << 2 * L + 1 << "\n";
        } else {
            auto i = lower_bound(begin(c), end(c), l);
            if (i != c.end() && (*i) < r)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
    }
    return 0;
}