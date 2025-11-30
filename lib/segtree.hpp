#pragma once
#include <vector>
#include <numeric>

// Disjoint Set Union (Union-Find) with path compression and union by rank
// Works in O(α(n)) amortized per operation.
// Template parameter T: index type (e.g., int, long long)
// Usage:
//   DSU<int> dsu(n);
//   dsu.unite(u, v);
//   bool sameSet = dsu.same(u, v);
//   int root = dsu.find(u);

template<typename T = int>
struct DSU {
    T n;
    std::vector<T> parent;
    std::vector<int> rank;

    // Initialize n elements: [0..n-1]
    explicit DSU(T _n)
        : n(_n), parent(_n), rank(static_cast<size_t>(_n), 0) {
        std::iota(parent.begin(), parent.end(), static_cast<T>(0));
    }

    // Find the root of x with path compression
    T find(T x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    // Merge sets containing a and b; returns true if merged, false if already in same set
    bool unite(T a, T b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        // union by rank
        if (rank[a] < rank[b]) std::swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return true;
    }

    // Check if a and b are in the same set
    bool same(T a, T b) {
        return find(a) == find(b);
    }
};
