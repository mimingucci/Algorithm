/*
 * author:  mimingucci
 * created: [Sat] Jan 11, 2025 19:24:51
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
    std::vector<int> a(n + 1, int(0));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    std::vector<int> b(n + 1, int(0));
    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];
        a[i] += b[i];
        int c = n - i;
        if (c <= a[i]) {
            if (i + 1 <= n) {
                b[i + 1]++;
                a[i] -= c;
            }
        } else {
            if (i + 1 <= n) {
                b[i + 1]++;
                b[i + a[i] + 1]--;
                a[i] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
    return 0;
}