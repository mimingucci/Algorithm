#pragma once
#include <vector>
#include <queue>
#include <utility>
#include <limits>

// graph.hpp: A flexible graph template for competitive programming
// Supports unweighted/weighted, directed/undirected graphs with common algorithms.

namespace cp {

    template<typename T=int>
    struct Edge {
        int to;
        T weight;
        Edge(int _to, T _weight = 1) : to(_to), weight(_weight) {}
    };

    template<typename T=int>
    struct Graph {
        int n;
        bool directed;
        std::vector<std::vector<Edge<T>>> adj;

        // Initialize graph with n vertices (0..n-1)
        explicit Graph(int _n, bool _directed = false)
            : n(_n), directed(_directed), adj(_n) {}

        // Add edge u -> v (and v -> u if undirected)
        void addEdge(int u, int v, T w = 1) {
            adj[u].emplace_back(v, w);
            if (!directed) adj[v].emplace_back(u, w);
        }

        // BFS from source; returns vector of distances (INT_MAX if unreachable)
        std::vector<int> bfs(int src) const {
            std::vector<int> dist(n, std::numeric_limits<int>::max());
            std::queue<int> q;
            dist[src] = 0;
            q.push(src);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto &e : adj[u]) {
                    if (dist[e.to] == std::numeric_limits<int>::max()) {
                        dist[e.to] = dist[u] + 1;
                        q.push(e.to);
                    }
                }
            }
            return dist;
        }

        // DFS: recursive
        void dfsUtil(int u, std::vector<bool> &vis, std::vector<int> &order) const {
            vis[u] = true;
            order.push_back(u);
            for (auto &e : adj[u]) {
                if (!vis[e.to]) dfsUtil(e.to, vis, order);
            }
        }

        // DFS from src; returns order of visit
        std::vector<int> dfs(int src) const {
            std::vector<bool> vis(n, false);
            std::vector<int> order;
            dfsUtil(src, vis, order);
            return order;
        }

        // Dijkstra's algorithm; returns vector of distances from src
        std::vector<T> dijkstra(int src) const {
            const T INF = std::numeric_limits<T>::max();
            std::vector<T> dist(n, INF);
            dist[src] = T(0);
            using P = std::pair<T,int>;
            std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
            pq.emplace(0, src);
            while (!pq.empty()) {
                auto [d,u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;
                for (auto &e : adj[u]) {
                    if (dist[e.to] > d + e.weight) {
                        dist[e.to] = d + e.weight;
                        pq.emplace(dist[e.to], e.to);
                    }
                }
            }
            return dist;
        }

        // Topological sort (Kahn's algorithm); only for DAG
        std::vector<int> topoSort() const {
            std::vector<int> indeg(n, 0);
            for (int u = 0; u < n; ++u) {
                for (auto &e : adj[u]) ++indeg[e.to];
            }
            std::queue<int> q;
            for (int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);
            std::vector<int> order;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                order.push_back(u);
                for (auto &e : adj[u]) {
                    if (--indeg[e.to] == 0) q.push(e.to);
                }
            }
            return order;
        }
    };

} // namespace cp
