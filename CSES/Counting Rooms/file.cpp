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

const ii MAX_N=1001;
ii n, m;
bool visited[MAX_N][MAX_N];
char grid[MAX_N][MAX_N];

void dfs(ii x, ii y){
	if(visited[x][y] || x<=0 || x>n || y<=0 || y>m || grid[x][y]=='#' )return;
	visited[x][y]=true;
	dfs(x-1, y);
	dfs(x+1, y);
	dfs(x, y-1);
	dfs(x, y+1);
}

int main()
{ 
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
 
    for(ii i=1; i<=n; i++){
    	for(ii j=1; j<=m; j++)
    		cin>>grid[i][j];
    }
    fill(*visited, *visited+MAX_N*MAX_N, false);
    ii conected=0;
    for(ii i=1; i<=n; i++){
    	for(ii j=1; j<=m; j++){
    		if(!visited[i][j] && grid[i][j]=='.'){
    			++conected;
    			dfs(i, j);
               
    		}
    	}
    }
    cout<<conected;
 
    
	return 0;
}