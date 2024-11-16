/*
 * author:  mimingucci
 * created: [Sat] Nov 16, 2024 20:04:32
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

struct DSU {
    vector<int> e;
    std::vector<int> left, right;
    DSU(int n) {
        e = vector<int>(n, -1);
        left = std::vector<int>(n);
        right = std::vector<int>(n);
        for (int i = 0; i < n; i++)
            left[i] = right[i] = i;
    }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool same_set(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }

    pair<int, int> getLR(int x) {
        int p = get(x);
        return {left[p], right[p]};
    }

    bool unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) {
            return false;
        }
        if (size(a) > size(b)) {
            swap(a, b);
        }
        e[a] += e[b];
        e[b] = a;
        left[a] = min(left[a], left[b]);
        right[a] = max(right[a], right[b]);
        return true;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    std::map<int, int> color;
    std::map<int, int> p;
    for (int i = 1; i <= n; i++) {
        color[i] = i;
        p[i] = 1;
    }
    DSU dsu = DSU(n + 1);
    while (q--) {
        int type;
        cin >> type;
        if (type == 2) {
            int c;
            cin >> c;
            cout << p[c] << '\n';
            continue;
        }
        int x, c;
        cin >> x >> c;
        p[color[dsu.get(x)]] -= dsu.size(x);
        color[dsu.get(x)] = c;
        p[c] += dsu.size(x);
        auto [l, r] = dsu.getLR(x);
        if (l > 1) {
            int y = dsu.get(l - 1);
            if (color[y] == c) {
                dsu.unite(l - 1, x);
            }
        }
        if (r < n) {
            int y = dsu.get(r + 1);
            if (color[y] == c) {
                dsu.unite(r + 1, x);
            }
        }
    }
    return 0;
}