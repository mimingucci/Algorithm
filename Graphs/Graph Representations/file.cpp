#include <bits/stdc++.h>
using namespace std;
#define maxN 1001
int n;
std::vector<int> adj[maxN];
std::vector<pair<int, int>> edges;
int matrix[maxN][maxN];

void convertMatrixToAdj(){
    for(int i=1; i<=n; i++){
    	for(int j=1; j<=n; j++){
    		if(matrix[i][j]==1){
    		  adj[i].push_back(j);
    	    }
    	}
    }
}

void convertMatrixToEdges(){
    for(int i=1; i<=n; i++){
    	for(int j=1; j<=n; j++){
    		if(matrix[i][j]==1 && i<j){
    			edges.push_back({i, j});
    		}
    	}
    }
}

void convertAdjToEdges(){
	for(int i=1; i<=n; i++){
		for(int x : adj[i]){
			if(x>i){
				edges.push_back({i, x});
			}
		}
	}
}

void convertEdgesToAdj(){
	for(auto x : edges){
		adj[x.first].push_back(x.second);
		adj[x.second].push_back(x.first);
	}
}

void convertEdgesToMatrix(){
	for(auto x : edges){
		matrix[x.first][x.second]=1;
		matrix[x.second][x.first]=1;
	}
}

int main(){
	std::cin.tie(0)->sync_with_stdio(0);
	cin >> n;
    int m;
    cin >> m;
    while(m--){
    	int x, y;
    	cin>>x>>y;
    	matrix[x][y]=matrix[y][x]=1;
    }
	return 0;
}