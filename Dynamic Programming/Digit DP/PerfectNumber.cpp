/*
author: mimingucci
created on: 1/8/2024 11:48:11 PM
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

//link: https://codeforces.com/contest/919/problem/B

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int k;
    cin>>k;
    int l=1;
    int r=INF;
    auto check=[&](int i)->int{
       string s=to_string(i);
       int n=s.size();
       int cnt=0;
       int dp[n+1][11][2];
       for(int i=0; i<=n; i++){
        for(int j=0; j<=10; j++){
            for(int f=0; f<=1; f++){
                dp[i][j][f]=0;
            }
        }
       }
       for(int i=0; i<10; i++){
        if(i>(s[0]-'0'))break;
        if(i==(s[0]-'0')){
            dp[1][i][0]=1;
        }else{
            dp[1][i][1]=1;
        }
       }
       for(int i=1; i<n; i++){
        for(int j=0; j<=10; j++){
            for(int f=0; f<2; f++){
                if(dp[i][j][f]==0)continue;
                for(int g=0; g<10; g++){
                    if(j+g>10)break;
                    if(f==0 && g>(s[i]-'0'))break;
                    if(f==0){
                        if(g==(s[i]-'0')){
                            dp[i+1][j+g][0]+=dp[i][j][f];
                        }else{
                            dp[i+1][j+g][1]+=dp[i][j][f];
                        }
                    }
                    if(f==1){
                        dp[i+1][j+g][1]+=dp[i][j][f];
                    }
                }
            }
        }
       }
       return dp[n][10][0]+dp[n][10][1];
    };
    while(r-1>l){
        int mid=(r+l)/2;
        if(check(mid)>=k){
            r=mid;
        }else{
            l=mid;
        }
    }
    if(check(l)==k){
        cout<<l;
    }else{
        cout<<r;
    }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */