/*
author: mimingucci
created on: 1/9/2024 1:03:17 PM
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

//link: https://codeforces.com/gym/100886/problem/G

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int A, B;
    cin>>A>>B;
    string a=to_string(A);
    string b=to_string(B);
    while(a.size()<b.size()){
        a="0"+a;
    }
    int n=a.size();
    string dp[n+1][2][2];
    for(int i=0; i<=n; i++){
        for(int j=0; j<2; j++){
            for(int f=0; f<2; f++){
                dp[i][j][f]="-1";
            }
        }
    }
    auto compare=[&](string x, string y)->string{
        if(x=="-1")return y;
        if(y=="-1")return x;
        int xx=1;
        int yy=1;
        bool started_a=false;
        bool started_b=false;
        for(char xxx : x){
            if(xxx=='0' && !started_a)continue;
            started_a=true;
            xx*=(xxx-'0');
        }
        if(!started_a)xx=0;
        for(char yyy : y){
            if(yyy=='0' && !started_b)continue;
            started_b=true;
            yy*=(yyy-'0');
        }
        if(!started_b)yy=0;
        if(xx==yy){
            return x;
        }else{
            if(xx<yy){
                return y;
            }else{
                return x;
            }
        }
    };
    for(int i=0; i<=9; i++){
        if(i<(a[0]-'0'))continue;
        if(i>(b[0]-'0'))continue;
        if(i==(a[0]-'0') && i<(b[0]-'0')){
            dp[1][0][1]=to_string(i);
        }
        if(i==(b[0]-'0') && i>(a[0]-'0')){
            dp[1][1][0]=to_string(i);
        }
        if(i==(b[0]-'0') && i==(a[0]-'0')){
            dp[1][0][0]=to_string(i);
        }
        if(i<(b[0]-'0') && i>(a[0]-'0')){
            dp[1][1][1]=to_string(i);
        }
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<2; j++){
            for(int f=0; f<2; f++){
                if(dp[i][j][f]=="-1")continue;
                for(int g=0; g<10; g++){
                    if(j==0 && f==0){
                        if(g>=(a[i]-'0') && g<=(b[i]-'0')){
                            if(g==(a[i]-'0') && g==(b[i]-'0')){
                                dp[i+1][0][0]=compare(dp[i+1][0][0], dp[i][j][f]+to_string(g));
                            }
                            if(g>(a[i]-'0') && g==(b[i]-'0')){
                                dp[i+1][1][0]=compare(dp[i+1][1][0], dp[i][j][f]+to_string(g));
                            }
                            if(g==(a[i]-'0') && g<(b[i]-'0')){
                                dp[i+1][0][1]=compare(dp[i+1][0][1], dp[i][j][f]+to_string(g));
                            }
                            if(g>(a[i]-'0') && g<(b[i]-'0')){
                                dp[i+1][1][1]=compare(dp[i+1][1][1], dp[i][j][f]+to_string(g));
                            }
                        }
                    }
                    if(j==0 && f==1){
                        if(g==(a[i]-'0')){
                            dp[i+1][0][1]=compare(dp[i+1][0][1], dp[i][j][f]+to_string(g));
                        }
                        if(g>(a[i]-'0')){
                            dp[i+1][1][1]=compare(dp[i+1][1][1], dp[i][j][f]+to_string(g));
                        }
                    }
                    if(j==1 && f==0){
                        if(g==(b[i]-'0')){
                            dp[i+1][1][0]=compare(dp[i+1][1][0], dp[i][j][f]+to_string(g));
                        }
                        if(g<(b[i]-'0')){
                            dp[i+1][1][1]=compare(dp[i+1][1][1], dp[i][j][f]+to_string(g));
                        }
                    }
                    if(j==1 && f==1){
                        dp[i+1][1][1]=compare(dp[i+1][1][1], dp[i][j][f]+to_string(g));
                    }
                }
            }
        }
    }
    string ans="0";
    ans=compare(ans, dp[n][0][1]);
    ans=compare(ans, dp[n][1][0]);
    ans=compare(ans, dp[n][0][0]);
    ans=compare(ans, dp[n][1][1]);
    reverse(begin(ans), end(ans));
    while(ans.size()>1 && ans.back()=='0')ans.pop_back();
    reverse(begin(ans), end(ans));
    if(ans=="0")ans=b;
    cout<<ans;    
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */