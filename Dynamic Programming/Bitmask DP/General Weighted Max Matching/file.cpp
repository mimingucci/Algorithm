/*
author: mimingucci
created on: 9/7/2023 7:22:13 AM
source: https://atcoder.jp/contests/abc318/tasks/abc318_d
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    std::vector<std::vector<int>> d(n, std::vector<int> (n, 0));
    for(int i=0; i<n-1; i++){
       for(int j=i+1; j<n; j++){
       	cin>>d[i][j];
       }
    }
    std::vector<int> f(1<<n, 0);
    for(int i=0; i<(1<<n)-1; i++){
    	int pivot=-1;
    	for(int j=0; j<n; j++){
    		if(!((i>>j)&1)){
    			pivot=j;
    			break;
    		}
    	}
    	for(int j=0; j<n; j++){
            if(!((i>>j)&1)){
    			int x=i | (1<<pivot) | (1<<j);
    			f[x]=max(f[x], f[i]+d[pivot][j]); 
    		}
    	}
    }
    cout<<f.back();
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */