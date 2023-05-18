#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define vdl vector<double long>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vpil vector<pair<int, long long>>
#define vpli vector<pair<long long, int>>
#define sort(A) sort(A.begin(), A.end())
#define input(A) for(auto &x : A)cin>>x
#define output(A) for(auto &x : A)cout<<x<<" "
#define dbg(v) cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << '\n';
int main()
{ 
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    ll f[n+1][n+1];
    fill(*f, *f + (n+1)*(n+1), 0);
    ll grid[n+1][n+1];
    for(ll i=1; i<=n; i++){
    	for(ll j=1; j<=n; j++){
    		char x;
    		cin>>x;
    		if(x=='.'){
               grid[i][j]=0;
    		}else{
    			grid[i][j]=1;
    		}
    	}
    }
    if(grid[1][1]==1){
    	cout<<0;
    }else{
        for(ll i=1; i<=n; i++){
    	for(ll j=1; j<=n; j++){
    		if(i==1 && j==1){
    			f[i][j]=1;
    		}else{
    			if(grid[i][j]==1){
    				f[i][j]=0;
    			}else{
    				f[i][j]=(f[i-1][j]+f[i][j-1])%1000000007;
    			}
    		}
    	}
    }
    cout<<f[n][n];
    }
    
	return 0;
}