/*
author: mimingucci
created on: 11/17/2023 12:09:53 AM
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
const int INF=(int)1<<62;
const int MAXN= 1e6;
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

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    std::vector<std::vector<pair<int, int>>> adj(n+1);
    for(int i=0; i<m; i++){
       int a, b, c;
       cin>>a>>b>>c;
       adj[a].push_back({c, b});
       adj[b].push_back({c, a});
    }
    int ans=prim(n, adj);
    if(ans<0){
    	cout<<"IMPOSSIBLE";
    }else{
    	cout<<ans;
    }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */