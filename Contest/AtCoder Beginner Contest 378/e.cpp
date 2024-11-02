/*
 * author:  mimingucci
 * created: [Sat] Nov 02, 2024 19:28:31
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

struct FenwickTree {
    std::vector<int> bit;
    int n;
    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
    FenwickTree(std::vector<int> a) : FenwickTree(a.size()) {
        for (int i = 0; i < a.size(); i++) {
            add(i, a[i]);
        }
    }
    void add(int idx, int value) {
        for (++idx; idx < n; idx += idx & (-idx)) {
            bit[idx] += value;
        }
    }
    int sum(int r) {
        int res = 0;
        for (++r; r > 0; r -= r & (-r)) {
            res += bit[r];
        }
        return res;
    }
    int sum(int l, int r) { return sum(r) - sum(l - 1); }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    FenwickTree fenwick(m);
    FenwickTree cnt(m);
    int ans = 0;
    int cur = 0;
    int cnt0 = 0;
    int sum0 = 0;
    for (int i = 1; i <= n; i++) {
        cur += a[i];
        int sum = 0;
        int x = cur % m;
        ans += x;
        int count = 0;
        if (x + 1 < m) {
            count = cnt.sum(x + 1, m - 1);
            sum = fenwick.sum(x + 1, m - 1);
            ans += count * (x + m) - sum;
        }
        if (x) {
            if (x - 1 > 0) {
                sum = fenwick.sum(1, x - 1);
                count = cnt.sum(1, x - 1) + cnt0;
            } else {
                sum = sum0;
                count = cnt0;
            }
            ans += x * count - sum;
        }
        if (x) {
            fenwick.add(x, x);
            cnt.add(x, 1);
        } else {
            cnt0++;
        }
    }
    cout << ans;
    return 0;
}