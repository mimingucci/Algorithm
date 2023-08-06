#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define sort(A) sort(A.begin(), A.end())
#define input(A) for(auto &x : A)cin>>x
#define output(A) for(auto &x : A)cout<<x<<" "
#define dbg(v) cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << '\n';
#define bit(n, i) ((n>>i)&1)

main()
{ 
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1; i<=n; i++)cin>>a[i];
    bool f[n+1][100001];
    f[0][0]=true;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=100000; j++){
            f[i][j]=f[i-1][j];
            int prev=j-a[i];
            if(prev>=0 && f[i-1][prev]){
                f[i][j]=true;
            }
        }
    }
    set<int> ans;
    for(int i=1; i<=100000; i++){
        if(f[n][i])ans.insert(i);
    }
    cout<<ans.size()<<'\n';
    for(int i : ans){
        cout<<i<<" ";
    }
}


