#include <bits/stdc++.h>
using namespace std;
#define maxN 1001
int n, m;
std::vector<int> topo;
std::vector<int> adj[maxN];
bool visited[maxN];

void dfs(int u){
	visited[u]=true;
	for(int v : adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
	topo.push_back(u);
}


int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	memset(visited, false, sizeof(visited));
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	reverse(topo.begin(), topo.end());
	for(int i : topo){
		cout << i << " ";
	}
	return 0;
}