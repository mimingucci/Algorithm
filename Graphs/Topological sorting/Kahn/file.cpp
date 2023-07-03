#include <bits/stdc++.h>
using namespace std;
#define maxN 1001
int n, m;
std::vector<int> topo;
std::vector<int> adj[maxN];
int in[maxN];

void kahn(){
	queue<int> q;
	for(int i=1; i<=n; i++){
		if(in[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		topo.push_back(u);
		for(int v : adj[u]){
			--in[v];
			if(in[v]==0){
				q.push(v);
			}
		}
	}
    for(int i : topo){
    	cout << i << " ";
    }
}


int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		++in[y];
	}
	kahn();
	return 0;
}