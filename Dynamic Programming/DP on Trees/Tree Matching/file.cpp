/*
author: mimingucci
created on: 2/18/2024 10:08:05 PM
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

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    std::vector<std::vector<int>> adj(n+1);
    for(int i=1; i<n; i++){
    	int u, v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    std::vector<std::vector<int>> dp(n+1, std::vector<int> (2, 0));
    auto dfs=[&](auto self, int u, int p)->void{
        for(int v : adj[u]){
        	if(v!=p){
        		self(self, v, u);
        		dp[u][0]+=max(dp[v][0], dp[v][1]);
        	}
        }
        for(int v : adj[u]){
        	if(v!=p){
        		dp[u][1]=max(dp[u][1], dp[u][0]+dp[v][0]+1-max(dp[v][0], dp[v][1]));
        	}
        }
    };
    dfs(dfs, 1, 0);
    cout<<max(dp[1][0], dp[1][1]);
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */