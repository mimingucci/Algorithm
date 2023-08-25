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
#define PI (2 * acos(0.0))

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
       int n, m;
       cin>>n>>m;
       char a[n+1][m+1];
       for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
       }
       char ans[]={ 'v', 'i', 'k', 'a'};
       int now=0;
       for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(now<4){
                if(ans[now]==a[j][i]){
                    ++now;
                    break;
                }
            }
        }
       }
       if(now==4){
        cout<<"YES\n";
       }else{
        cout<<"NO\n";
       }
    }
}