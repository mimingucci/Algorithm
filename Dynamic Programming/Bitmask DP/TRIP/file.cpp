#include <bits/stdc++.h>
using namespace std;
#define bit(n, i) ((n>>i)&1)
int main(){
	cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    int c[16][16];
    for(int i=0; i<n; i++)
    	for(int j=0; j<n; j++)
    		cin>>c[i][j];
    int f[1<<17][17];
    for(int i=1; i<(1<<n); i++){
    	if(__builtin_popcount(i)==1){
    		continue;
    	}else{
    		for(int j=0; j<n; j++){
    			if(bit(i, j)){
    				int prev=i-(1<<j);
    				f[i][j]=1e9;
    				for(int k=0; k<n; k++){
    					if(bit(prev, k)){
    						f[i][j]=min(f[i][j], f[prev][k]+c[k][j]);
    					}
    				}
    			}
    		}
    	}
    }
    int ans=1e9;
    for(int i=0; i<n; i++)ans=min(ans, f[(1<<n)-1][i]);
    	cout<<ans;
	return 0;
}