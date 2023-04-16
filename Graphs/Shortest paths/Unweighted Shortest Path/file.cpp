#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define vdl vector<double long>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vpil vector<pair<int, long long>>
#define vpli vector<pair<long long, int>>
#define ii int64_t
#define sort(A) sort(A.begin(), A.end())
#define input(A) for(auto &x : A)cin>>x
#define output(A) for(auto &x : A)cout<<x<<" "
#define dbg(v) cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << '\n';
#define bit(n, i) ((n>>i)&1)
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	cin>>N>>M;
	vi dist(N+1, -1), parent(N+1);
	vector<int> adj[N+1];
	for(int i=1; i<=M; i++){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dist[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i : adj[x]){
			if(dist[i]==-1){
				dist[i]=dist[x]+1;
				parent[i]=x;
				q.push(i);
			}
		}
	}
	if(dist[N]==-1){
		cout<<"IMPOSSIBLE";
	}else{
		cout<<dist[N]+1<<'\n';
		vi path;
		path.push_back(N);
		while(path.back()!=1){
			path.push_back(parent[path.back()]);
		}
		reverse(path.begin(), path.end());
		for(int i : path){
			cout<<i<<" ";
		}
	}
	return 0;
}