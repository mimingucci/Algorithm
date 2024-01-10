/*
author: mimingucci
created on: 1/10/2024 9:59:05 PM
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
const int MOD=1e9+7;

//link: https://codeforces.com/contest/628/problem/D

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int m, d;
    cin>>m>>d;
    string a, b;
    cin>>a>>b;
    auto check=[&](string s, bool get)->int{
       int n=s.size();
       if(n==1){
         int ss=stoi(s);
         int ans=0;
         if(get){
            for(int i=0; i<=ss; i++){
               if(i%m==0 && i!=d)++ans;
            }
         }else{
            for(int i=0; i<ss; i++){
               if(i%m==0 && i!=d)++ans;
            }
         }
         return ans;
       }
       int dp[n+1][m][2];
       for(int i=0; i<=n; i++){
         for(int j=0; j<m; j++){
            for(int f=0; f<2; f++){
               dp[i][j][f]=0;
            }
         }
       }
       for(int i=1; i<10; i++){
         if(i>(s[0]-'0'))break;
         if(i!=d){
            if(i==(s[0]-'0')){
               dp[1][i%m][0]+=1;
            }else{
               dp[1][i%m][1]+=1;
            }
         }
       }
       for(int i=1; i<n; i++){
         for(int j=0; j<m; j++){
            for(int f=0; f<2; f++){
               if(dp[i][j][f]==0)continue;
               for(int g=0; g<10; g++){
                  if(i%2==1){
                     if(g!=d)continue;
                     if(f==0){
                        if(g>(s[i]-'0'))continue;
                        if(g==(s[i]-'0')){
                           dp[i+1][(j*10+g)%m][0]+=dp[i][j][f];
                           dp[i+1][(j*10+g)%m][0]%=MOD;
                           continue;
                        }
                        dp[i+1][(j*10+g)%m][1]+=dp[i][j][f];
                        dp[i+1][(j*10+g)%m][1]%=MOD;
                        continue;
                     }else{
                        dp[i+1][(j*10+g)%m][1]+=dp[i][j][f];
                        dp[i+1][(j*10+g)%m][1]%=MOD;
                     }
                  }else{
                     if(g==d)continue;
                     if(f==0){
                        if(g>(s[i]-'0'))continue;
                        if(g==(s[i]-'0')){
                           dp[i+1][(j*10+g)%m][0]+=dp[i][j][f];
                           dp[i+1][(j*10+g)%m][0]%=MOD;
                           continue;
                        }
                        dp[i+1][(j*10+g)%m][1]+=dp[i][j][f];
                        dp[i+1][(j*10+g)%m][1]%=MOD;
                        continue;
                     }else{
                        dp[i+1][(j*10+g)%m][1]+=dp[i][j][f];
                        dp[i+1][(j*10+g)%m][1]%=MOD;
                     }
                  }
               }
            }
         }
       }
       int ans=dp[n][0][1]%MOD;
       if(get){
         ans+=dp[n][0][0];
         ans%=MOD;
       }
       return ans;
    };
    int ans=check(b, true)-check(a, false);
    while(ans<0)ans+=MOD;
    cout<<ans;
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */