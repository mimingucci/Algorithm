/*
 * author:  mimingucci
 * created: [Sat] Aug 03, 2024 16:23:18
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

// link problem: https://cses.fi/problemset/task/2079

int n;
vector<int> adj[MAXN];
int subtree_size[MAXN];

int get_subtree_size(int node, int parent = -1) {
    int &res = subtree_size[node];
    res = 1;
    for (int i : adj[node]) {
        if (i == parent) {
            continue;
        }
        res += get_subtree_size(i, node);
    }
    return res;
}

int get_centroid(int node, int parent = -1) {
    for (int i : adj[node]) {
        if (i == parent) {
            continue;
        }

        if (subtree_size[i] * 2 > n) {
            return get_centroid(i, node);
        }
    }
    return node;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    get_subtree_size(0);
    cout << get_centroid(0) + 1 << endl;
    return 0;
}