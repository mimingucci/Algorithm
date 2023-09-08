/*
author: mimingucci
created on: 9/8/2023 4:43:27 AM
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF=(int)1<<62;
const int MAXN= 1e6;

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
         double a, b, c;
         cin>>a>>b>>c;
         cout<<(int)(ceil(abs(a-b)/(2*c)))<<'\n';
    }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */