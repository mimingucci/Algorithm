/*
 * author:  mimingucci
 * created: [Sat] Feb 22, 2025 19:10:15
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    int i = 0;
    while (i < n - 1) {
        if (s[i] == 'W' && s[i + 1] == 'A') {
            s[i] = 'A';
            s[i + 1] = 'C';
            i = max(int(0), i - 1);
        } else {
            i++;
        }
    }
    cout << s << endl;
    return 0;
}
