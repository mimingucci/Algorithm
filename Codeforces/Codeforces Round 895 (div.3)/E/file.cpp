/*
author: mimingucci
created on: 9/9/2023 5:32:30 AM
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
         int n;
         cin>>n;
         std::vector<int> a(n+1);
         for(int i=1; i<=n; i++)cin>>a[i];
         string s;
         cin>>s;
         s="0"+s;   
         std::vector<int> prefix(n+1, 0);
         int x0=0;
         int x1=0;
         for(int i=1; i<=n; i++){
            prefix[i]=prefix[i-1]^a[i];
            if(s[i]=='0'){
                x0^=a[i];
            }else{
                x1^=a[i];
            }
         }
         int q;
         cin>>q;
         while(q--){
            int type;
            cin>>type;
            if(type==1){
                int l, r;
                cin>>l>>r;
                x0^=(prefix[r]^prefix[l-1]);
                x1^=(prefix[r]^prefix[l-1]);
            }else{
                int i;
                cin>>i;
                if(i==0){
                    cout<<x0<<" ";
                }else{
                    cout<<x1<<" ";
                }
            }
         }
         cout<<'\n';            
    }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */