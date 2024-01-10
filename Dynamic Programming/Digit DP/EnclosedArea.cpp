/*
author: mimingucci
created on: 1/9/2024 2:13:32 PM
*/
#include <bits/stdc++.h>
using namespace std;
const int64_t INF=(int64_t)1<<62;
const int64_t font[10]={1, 0, 0, 0, 0, 0, 1, 0, 2, 1};

class EnclosedArea{
   public:
     int64_t construct(int E, int N){
        N++;
        int64_t l=int64_t(1);
        int64_t r=INF;
        auto check=[&](int64_t x)->int64_t{
           string s=to_string(x);
           int64_t n=s.size(); 
           int64_t dp[n+1][50][2][2];
           for(int i=0; i<n+1; i++){
            for(int j=0; j<50; j++){
                for(int f=0; f<2; f++){
                    for(int g=0; g<2; g++)
                       dp[i][j][f][g]=int64_t(0);
                }
            }
           }
           for(int g=0; g<10; g++){
            if(g>(s[0]-'0'))break;
            if(g==(s[0]-'0')){
                dp[1][font[g]][0][1]+=int64_t(1);  
            }else{
                if(g==0){
                  dp[1][0][1][0]+=int64_t(1);
                }else{
                  dp[1][font[g]][1][1]+=int64_t(1);  
                }
            }
           }
           for(int i=1; i<n; i++){
             for(int j=0; j<=E; j++){
                for(int f=0; f<2; f++){
                   for(int h=0; h<2; h++){
                       if(dp[i][j][f][h]==0)continue;
                       for(int g=0; g<10; g++){
                          if(h==0){
                            if(g==0){
                                dp[i+1][0][1][h]+=dp[i][j][f][h];
                            }else{
                                dp[i+1][font[g]][1][1]+=dp[i][j][f][h];
                            }
                          }else{
                            if(font[g]+j>E)continue;
                            if(f==0){
                                if(g>s[i]-'0')continue;
                                if(g==s[i]-'0'){
                                    dp[i+1][j+font[g]][f][h]+=dp[i][j][f][h];
                                }else{
                                    dp[i+1][j+font[g]][1][h]+=dp[i][j][f][h];                                    
                                }
                            }else{
                                dp[i+1][j+font[g]][1][1]+=dp[i][j][f][h];
                            }
                          }
                       }
                   } 
                }
             }
           }
           return dp[n][E][1][1]+dp[n][E][0][1];
        };
        while(r-1>l){
            int64_t mid=(r+l)/2;
            if(check(mid)>=N){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        if(check(l)>=N){
            return l;
        }else{
            return r;
        }
     }
};

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */