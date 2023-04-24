#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    int grid[n][n];
    fill(grid, grid+n*n, 0);
    for(int i=0; i<n; i++)
    	for(int j=0; j<n; j++)
    		cin>>grid[i][j];
    int sum[n][n];
    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		sum[i][j]=max(sum[i-1][j], sum[i][j-1])+grid[i][j];
    	}
    }
    cout<<sum[n-1][n-1]<<'\n';
	return 0;
}