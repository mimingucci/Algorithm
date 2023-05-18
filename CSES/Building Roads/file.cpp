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
const ii MAX_N=1e6;
ii n, m;
vector<ii> adj[MAX_N];
bool visited[MAX_N];
vector<ii> pass;

void dfs(ii x){
	if(visited[x])return;
    visited[x]=true;
    //process x
    for(auto a : adj[x]){
    	dfs(a);
    }
}

int main()
{ 
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>m;
    for(ii i=0; i<m; i++){
    	ii a, b;
    	cin>>a>>b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    vector<pair<ii, ii>> res;
    fill_n(visited, MAX_N, false);
    for(ii i=1; i<=n; i++){
       if(visited[i]==false){
          visited[i]=true;
          pass.push_back(i);
          for(auto j : adj[i]){
              dfs(j);
          }
       }
    }
    cout<<pass.size()-1<<'\n';
    for(ii i=0; i<pass.size()-1; i++){
    	cout<<pass[i]<<" "<<pass[i+1]<<'\n';
    }
	return 0;
}