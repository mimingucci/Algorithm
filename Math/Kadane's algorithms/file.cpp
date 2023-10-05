/*
author: mimingucci
created on: 10/2/2023 9:05:38 PM
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF=(int)1<<62;

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
         int max_so_far=-INF;
         int max_end_here=0;
         int n;
         cin>>n;
         std::vector<int> a(n);
         for(int i=0; i<n; i++)cin>>a[i];
         for(int i=0; i<n; i++){
            max_end_here+=a[i];
            max_so_far=max(max_so_far, max_end_here);
            max_end_here=max(max_end_here, int(0));
         } 
         cout<<max_so_far<<'\n';
    }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */