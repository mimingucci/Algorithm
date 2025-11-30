#pragma once
#include <vector>

// Fenwick Tree (Binary Indexed Tree) for point updates and prefix sums
// Supports O(log N) update and prefix query.
// Template parameter T: the numeric type (int, long long, mint, etc.)
// Usage:
//   Fenwick<long long> fw(n);
//   fw.update(i, delta);            // add delta at index i (0-based)
//   T sum = fw.query(r);           // get sum on [0..r)
//   T range = fw.query(r) - fw.query(l); // sum on [l..r)

template<typename T>
struct Fenwick {
    int n;
    std::vector<T> bit;

    // Initialize Fenwick Tree of size _n (all zeros)
    explicit Fenwick(int _n)
        : n(_n), bit(_n, T(0)) {}

    // add val to element at index idx (0-based)
    void update(int idx, T val) {
        for (int i = idx + 1; i <= n; i += i & -i) {
            bit[i - 1] += val;
        }
    }

    // prefix sum on [0..r) (0-based)
    T query(int r) const {
        T res = T(0);
        for (int i = r; i > 0; i -= i & -i) {
            res += bit[i - 1];
        }
        return res;
    }

    // sum on [l..r) (0-based)
    T range_query(int l, int r) const {
        return query(r) - query(l);
    }

    // get single element at index idx (0-based)
    T get(int idx) const {
        return range_query(idx, idx + 1);
    }
};
