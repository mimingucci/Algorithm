#include <bits/stdc++.h>
using namespace std;
#define bit(i, n) ((n>>i)&1)
int main(){
	cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    int res=-1e9;
    int grid[4][n+1];
    for(int i=0; i<4; i++){
    	for(int j=1; j<=n; j++){
    		cin>>grid[i][j];
    		res=max(res, grid[i][j]);
    	}
    }
    if(res<=0){
    	cout<<res;
    }else{

       bool isOk[16];
    for(int i=0; i<15; i++){
    	bool ok=true;
    	for(int j=0; j<3; j++){
    		if(bit(j, i) && bit(j+1, i)){
              ok=false;
    		}
    	}
    	isOk[i]=ok;
    }
    int f[n+1][16];
    for(int i=1; i<=n; i++){
    	for(int j=0; j<16; j++){
    		
    		if(isOk[j]){
    			f[i][j]=-1e9;
                int sum=0;
    		    for(int m=0; m<4; m++){
    			if(bit(m, j)){
    				sum+=grid[m][i];
    			}
    		    }
    		    for(int k=0; k<16; k++){
    			if(((j&k)==0) && isOk[k]){
    				f[i][j]=max(f[i][j], f[i-1][k]+sum);
    			}
    		    }
    		}
    		
    	}
    }
    int maxx=INT_MIN;
    for(int i=0; i<16; i++){
    	if(isOk[i])
    	maxx=max(maxx, f[n][i]);
    }
    cout<<maxx;
    }
   
	return 0;
}