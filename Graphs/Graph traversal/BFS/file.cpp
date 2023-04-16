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
ii N=1000000;
bool visited[N];
vector<ii> adj[N];
ii distance[N];
void bfs(ii s){
   visited[s]=true;
   queue<ii> q;
   q.push(s);
   distance[s]=0;
   while(!q.empty()){
   	ii front=q.front();
   	q.pop();
   	// processing info
   	for(ii x : adj[front]){
   		if(visited[x])continue;
   		visited[x]=true;
   		distance[x]=distance[front]+1;
   		q.push(x);
   	}
   }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
	return 0;
}