/*
 * author:  mimingucci
 * created: [Sat] Sep 21, 2024 20:13:28
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

struct DSU {
    vector<int> e;
    std::vector<priority_queue<int>> s;
    DSU(int n) {
        e = vector<int>(n, -1);
        s = std::vector<priority_queue<int>>(n);
        for (int i = 0; i < n; i++) {
            s[i].push(i);
        }
    }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool same_set(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }

    int calc(int v, int k) {
        if (s[v].size() < k)
            return -1;
        std::vector<int> x;
        int res = 0;
        while (x.size() < k) {
            x.push_back(s[v].top());
            s[v].pop();
        }
        for (int i : x)
            s[v].push(i);
        return x.back();
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
        std::vector<int> new_elements;
        while (!s[b].empty()) {
            s[a].push(s[b].top());
            e[s[b].top()] = a;
            s[b].pop();
        }
        while (!s[a].empty()) {
            new_elements.push_back(s[a].top());
            s[a].pop();
        }
        while (new_elements.size() > 10)
            new_elements.pop_back();
        for (int i : new_elements)
            s[a].push(i);
        return true;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    DSU dsu(n + 1);
    while (q--) {
        int type, v, k;
        cin >> type >> v >> k;
        if (type == 1) {
            dsu.unite(v, k);
        } else {
            int x = dsu.get(v);
            cout << dsu.calc(x, k) << '\n';
        }
    }
    return 0;
}