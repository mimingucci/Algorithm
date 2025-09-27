/*
 * author:  mimingucci
 * created: [Sat] Sep 27, 2025 19:10:47
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    std::vector<int> a(n + 1, int(0));
    for (int i = 1; i <= n; i++) cin >> a[i];
    std::vector<int> suffix(n + 2, int(0)), prefix(n + 2, int(0));
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + a[i];
    for (int i = n; i >= 1; i--) suffix[i] = suffix[i + 1] + a[i];
    int now = 1;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int c;
            cin >> c;
            if (c < now) {
                now -= c;
            } else {
                c -= now;
                now = n;
                now -= c;
            }
        } else {
            int l, r;
            cin >> l >> r;
            if (now < l) {
                int ll = l - now + 1;
                int rr = r - now + 1;
                cout << prefix[rr] - prefix[ll - 1] << '\n';
                continue;
            }
            if (now > r) {
                int fn = n - now + 2;
                int ll = l - 1 + fn;
                int rr = r - 1 + fn;
                cout << prefix[rr] - prefix[ll - 1] << '\n';
                continue;
            }
            int x = r - now + 1;
            int y = n + 1 - (now - l);
            cout << prefix[x] + suffix[y] << '\n'; 
        }
    }
    return 0;
}
