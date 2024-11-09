/*
 * author:  mimingucci
 * created: [Sat] Nov 09, 2024 19:43:00
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int q;
    cin >> q;
    int now = 0;
    deque<int> pivot;
    std::map<int, int> map;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            map[now]++;
            if (pivot.empty() || pivot.back() < now)
                pivot.push_back(now);
            continue;
        }
        if (type == 2) {
            int t;
            cin >> t;
            now += t;
            continue;
        }
        int h;
        cin >> h;
        int ans = 0;
        int x = now - h;
        while (!pivot.empty() && pivot.front() <= x) {
            ans += map[pivot.front()];
            pivot.pop_front();
        }
        cout << ans << '\n';
    }
    return 0;
}