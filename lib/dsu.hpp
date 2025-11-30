#pragma once
#include <vector>
#include <numeric>

// dsu.hpp
// Disjoint Set Union (Union-Find) with path compression and union by rank
// Works in O(α(n)) amortized per operation.
// Template parameter I: index type (e.g., int, long long)
// Usage:
//   DSU<int> dsu(n);
//   dsu.unite(u, v);
//   bool same = dsu.same(u, v);
//   I root = dsu.find(u);

template<typename I = int>
struct DSU {
    std::vector<I> parent;
    std::vector<int> depth;

    // Initialize n elements: [0..n-1]
    explicit DSU(I n)
        : parent(static_cast<size_t>(n)), depth(static_cast<size_t>(n), 0) {
        std::iota(parent.begin(), parent.end(), static_cast<I>(0));
    }

    // Find root of x with path compression
    I find(I x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    // Merge sets containing a and b; returns true if merged
    bool unite(I a, I b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        // union by depth (rank)
        if (depth[a] < depth[b]) std::swap(a, b);
        parent[b] = a;
        if (depth[a] == depth[b]) depth[a]++;
        return true;
    }

    // Check if a and b are in the same set
    bool same(I a, I b) {
        return find(a) == find(b);
    }
};
