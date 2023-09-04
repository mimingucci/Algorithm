/*
author: mimingucci
created on: 9/4/2023 6:18:52 PM
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int MAXN= 502;

int f[MAXN][MAXN];

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin>>s;
    for(int j=0; j<=s.size(); j++){
    	for(int i=0; i<s.size()-j; i++){
    		f[i][i+j]=f[i+1][i+j]+1;
    		for(int k=i+1; k<=i+j; k++){
    			if(s[i]==s[k]){
    				f[i][i+j]=min(f[i][i+j], f[i+1][k-1]+f[k+1][i+j]);
    			}
    		}
    	}
    }
    cout<<f[0][s.size()-1];
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */