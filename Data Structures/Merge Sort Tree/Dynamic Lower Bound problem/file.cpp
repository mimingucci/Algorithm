// Statement:
// We are given an array a1,a2,a3...an and an integer q. The i_th of the next q
// lines has an integer ti, describing the type of query. If ti=0 then you are
// given two other integers, idxi and xi, meaning that we should make aidx=xi.
// If ti=1 then you are given three integers li,ri,xi. You should answer with
// the smallest value v in the range [li,ri] such that x≤v. If there is none,
// print -1.

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q, a[N];
multiset<int> seg[4 * N + 5];
void build(int node, int l, int r) {
    if (l == r) {
        seg[node].insert(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    for (int i = l; i <= r; i++)
        seg[node].insert(a[i]);
    return;
}
void edit(int node, int l, int r, int idx, int val) {
    if (l == r) {
        seg[node].erase(a[idx]);
        seg[node].insert(val);
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
        edit(node * 2, l, mid, idx, val);
    else
        edit(node * 2 + 1, mid + 1, r, idx, val);
    seg[node].erase(a[idx]);
    seg[node].insert(val);
    return;
}
int query(int node, int l, int r, int lx, int rx, int x) {
    if (l > rx || r < lx)
        return INT_MAX;
    if (l >= lx && r <= rx) {
        auto it = seg[node].lower_bound(x);
        if (it == seg[node].end())
            return INT_MAX;
        return *it;
    }
    int mid = (l + r) / 2;
    return min(query(node * 2, l, mid, lx, rx, x),
               query(node * 2 + 1, mid + 1, r, lx, rx, x));
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while (q--) {
        bool t;
        cin >> t;
        if (!t) {
            int idx, val;
            cin >> idx >> val;
            edit(1, 1, n, idx, val);
            a[idx] = val;
            continue;
        }
        int l, r, x;
        cin >> l >> r >> x;
        int y = query(1, 1, n, l, r, x);
        if (y == INT_MAX)
            cout << -1 << endl;
        else
            cout << y << endl;
    }
    return 0;
}