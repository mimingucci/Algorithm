#include <bits/stdc++.h>
using namespace std;
#define maxN 1001
bool visited[maxN];
std::vector<int> adj[maxN];
void dfs(int u){
   visited[u]=true;
   for(int v : adj[u]){
   	if(visited[v]==false){
   		dfs(v);
   	}
   }
}

int main(){
	std::cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
    memset(visited, false, sizeof(visited));
    int cnt=0;
    for(int i=1; i<=n; i++)
    	if(visited[i]==false && adj[i].size()>0){
    		dfs(i);
    		++cnt;
    	}
	return 0;
}