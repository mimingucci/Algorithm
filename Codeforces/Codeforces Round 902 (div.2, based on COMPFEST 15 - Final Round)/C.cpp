/*
author: mimingucci
created on: 10/9/2023 5:58:09 AM
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

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
         int n, m, k;
         cin>>n>>m>>k;
         if(k>3){
            cout<<0<<'\n';
            continue;
         }
         if(k==1){
            cout<<1<<'\n';
            continue;
         }
         if(m==0){
            cout<<0<<'\n';
            continue;
         }
         if(k==2){
            int ans=min(n-1, m);
            ans+=m/n;
            cout<<ans<<'\n';
            continue;
         }
         if(m<=n){
            cout<<0<<'\n';
         }else{
            int sub=m/n-1;
            sub=max(sub, int(0));
            cout<<m-n-sub<<'\n';
         }
    }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */