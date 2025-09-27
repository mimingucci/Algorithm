/*
 * author:  mimingucci
 * created: [Sat] Sep 27, 2025 19:03:40
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
    vector<int> a(n);
    vector<bool> has(n + 1, false);
    for (int &i : a) cin >> i;
    bool ok = true;
    for (int i : a) {
        if (i > 0) {
            if (has[i]) {
                ok = false;
            } else {
                has[i] = true;
            }
        }
    }
    int now = 1;
    if (!ok) {
        cout << "No";
        return 0;
    }
    while (now <= n && has[now]) now++;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            a[i] = now;
            now++;
            while (now <= n && has[now]) now++;
        }
    }
    cout << "Yes\n";
    for (int i : a) cout << i << " ";
    return 0;
}
