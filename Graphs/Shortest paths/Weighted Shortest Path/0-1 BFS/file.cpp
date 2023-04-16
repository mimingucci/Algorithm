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
	int n, m;
	cin>>n>>m;
	vector<pair<int, int>> adj[n+1];
    for(int i=1; i<=m; i++){
    	int u, v, w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    }
    deque<int> q;
    vector<int> d(n, INT_MAX);
    q.push_front(1);
    d[1]=0;
    while(!q.empty()){
    	int u=q.front();
    	q.pop_front();
    	for(auto edge : adj[u]){
           int v=edge.first;
           int w=edge.second;
           if(d[u]+w<d[v]){
           	d[v]=d[u]+w;
           }
           if(w==1){
           	q.push_back(v);
           }else{
           	q.push_front(v);
           }
    	}
    }
	return 0;
}