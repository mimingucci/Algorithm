/*
author: mimingucci
created on: 11/16/2023 11:46:03 PM
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

struct DSU {
	vector<int> e;

	DSU(int N) : e(N, -1) {}

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool connected(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) { return false; }
		if (e[x] > e[y]) { swap(x, y); }
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

template <class T> T kruskal(int N, vector<pair<T, pair<int, int>>> edges) {
	sort(edges.begin(), edges.end());
	T ans = 0;
	DSU D(N + 1);  // edges that unite are in MST
	for (pair<T, pair<int, int>> &e : edges) {
		if (D.unite(e.second.first, e.second.second)) { ans += e.first; }
	}
	// -1 if the graph is not connected, otherwise the sum of the edge lengths
	return (D.size(1) == N ? ans : -1);
}

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    std::vector<pair<int, pair<int, int>>> edges;
    for(int i=0; i<m; i++){
    	int a, b, c;
    	cin>>a>>b>>c;
    	edges.push_back({c, {a, b}});
    }
    int ans=kruskal(n, edges);
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