/*
author: mimingucci
created on: 11/4/2023 7:36:29 PM
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
int n, m;
std::vector<set<int>> adj;
std::vector<bool> setted;
std::vector<int> a;
std::vector<int> s;
std::vector<int> t;
bool isOk;
void dfs(int u){
	setted[u]=true;
	for(int v : adj[u]){
		if(setted[v]){
			if(a[u]==-1){
				a[u]=1-a[v];
			}else{
				if(a[u]==a[v]){
					isOk=false;
				}
			}
		}
	}
	if(!isOk){
		return;
	}
	for(int v : adj[u]){
		if(!setted[v]){
			dfs(v);
		}
	}
}

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    s.resize(m+1);
    t.resize(m+1);
    a.assign(n+1, -1);
    isOk=true;
    setted.assign(n+1, false);
    adj.resize(n+1);
    for(int i=1; i<=m; i++)cin>>s[i];
    for(int i=1; i<=m; i++)cin>>t[i];
    for(int i=1; i<=m; i++){
       if(s[i]==t[i]){
       	cout<<"No";
       	exit(0);
       }	
       adj[s[i]].insert(t[i]);
       adj[t[i]].insert(s[i]);
    }	
    for(int i=1; i<=n && isOk; i++){
    	if(!setted[i]){
    		dfs(i);
    	}
    }
    if(isOk){
    	cout<<"Yes";
    }else{
    	cout<<"No";
    }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */