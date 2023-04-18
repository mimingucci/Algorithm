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
//Finding connected components in a graph represented by a grid.
const int MAX_N=1000;
int grid[MAX_N][MAX_N];
int row_num;
int col_num;
bool visited[MAX_N][MAX_N];
int curr_size=0;
void flood_fill(int x, int y, int color){
	if((x<1 || x>row_num || y<1 || y> col_num) || grid[x][y]!=color || visited[x][y]){
		return;
	}
	visited[x][y]=true;
	++curr_size;
	flood_fill(x-1, y, color);
	flood_fill(x+1, y, color);
	flood_fill(x, y-1, color);
	flood_fill(x, y+1, color);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    cin>>row_num>>col_num;
    for(int i=1; i<=row_num; i++){
    	for(int j=1; j<=col_num; j++){
    		cin>>grid[i][j];
    	}
    }
    fill(visited, visited+MAX_N*MAX_N, false);
    for(int i=1; i<=row_num; i++){
    	for(int j=1; j<=col_num; j++){
    		if(!visited[i][j]){
    			curr_size=0;
    			flood_fill(i, j, grid[i][j]);
    		}
    	}
    }
	return 0;
}