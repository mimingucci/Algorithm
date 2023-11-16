//number of vertex n, index-based on 1
int prim(int n, const vector<vector<pair<int, int>>> &adj) {
	int weight = 0;
	vector<int> dist(n+1, INF);
	dist[1] = 0;
	set<pair<int, int>> q;
	// {cost, vertex}
	q.insert({0, 1});
	vector<bool> visited(n+1, false);
	for (int i = 1; i <= n; ++i) {
		if (q.empty()) { return -1; }
		int v = q.begin()->second;
		visited[v] = true;
		weight += q.begin()->first;
		q.erase(q.begin());

		for (auto &[cost, child] : adj[v]) {
			if (!visited[child] && cost < dist[child]) {
				q.erase({dist[child], child});
				dist[child] = cost;
				q.insert({cost, child});
			}
		}
	}
	return weight;
}