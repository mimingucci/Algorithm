/*
author: mimingucci
created on: 10/9/2023 6:12:35 AM
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
const int INF=(int)1<<62;
const int MAXN= 1e6;
const int MOD=998244353;
main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    std::vector<int> a(n+1);
    for(int i=1; i<=n; i++)cin>>a[i];
    a[0]=-INF;
    for(int i=1; i<=n; i++){
    	for(int j=2*i; j<=n; j+=i){
    		a[i]=max(a[i], a[j]);
    	}
    }	
    sort(begin(a), end(a));
    int ans=0;
    int now=1;
    for(int i=1; i<=n; i++){
    	ans+=now*a[i];
    	ans%=MOD;
        now*=2;
        now%=MOD;
    }
    cout<<ans;
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */