/*
author: mimingucci
created on: 9/8/2023 10:18:22 PM
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF=(int)1<<62;
const int MAXN= 1e6;

int sum(int l, int r){
   if(l>r)return 0;
   if((r-l+1)%2==0){
        return ((r-l+1)/2)*(r+l);
    }else{
        return ((r-l+1)/2)*(r+l)+(r+l)/2;
    }
}

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
         int n, x, y;
         cin>>n>>x>>y;
         if(x==y){
            cout<<0<<'\n';
            continue;
         }
         int ucln=std::lcm(x,y);
         int k=n/ucln;
         cout<<sum(n-(n/x-k)+1, n)-sum(1, n/y-k)<<'\n'; 
    }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */