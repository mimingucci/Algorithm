/*
author: mimingucci
created on: 11/4/2023 8:09:03 PM
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
const int INF=(int)1<<60;
const int MAXN= 1e6;

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    cout<<fixed<<setprecision(14);
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    int l=1;
    int r=n;
    std::vector<double> maxx(n+1, double(-INF));
    auto f=[&](int k){
       std::vector<std::vector<double>> dp(n+1, std::vector<double> (k+1, double(-INF)));
       for(int i=1; i<=n; i++){
        dp[i][1]=max(dp[i][1], double(pow(double(0.9), k-1))*double(a[i]));
        if(i>1)dp[i][1]=max(dp[i][1], dp[i-1][1]);
       }
       for(int i=2; i<=n; i++){
        for(int j=2; j<=k; j++){
            if(i>=j)
            dp[i][j]=max(dp[i][j], dp[i-1][j-1]+pow(double(0.9), k-j)*double(a[i]));
            if(i-1>=j)
            dp[i][j]=max(dp[i][j], dp[i-1][j]);    
        }
       }
       double mauso=0;
       for(int i=1; i<=k; i++){
        mauso+=double(pow(double(0.9), k-i));
       }
       double tuso=0;
       for(int i=k; i<=n; i++)tuso=max(tuso, dp[i][k]);
       return tuso/mauso-double(1200)/double(sqrt(k)); 
    };
    while (r - l > 4) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int f1 = maxx[m1]>-INF?maxx[m1]:f(m1);      
        int f2 = maxx[m2]>-INF?maxx[m2]:f(m2);
        maxx[m1]=f1;
        maxx[m2]=f2;      
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    double ans=double(-INF);
    for(int i=l; i<=r; i++)ans=max(ans, f(i));
    cout<<ans;
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */