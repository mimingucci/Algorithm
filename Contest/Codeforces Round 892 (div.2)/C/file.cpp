#include <bits/stdc++.h>
using namespace std;
#define int int64_t
// #define vi vector<int>
// #define vpii vector<pair<int, int>>
#define sort(A) sort(A.begin(), A.end())
#define input(A) for(auto &x : A)cin>>x
#define output(A) for(auto &x : A)cout<<x<<" "
#define dbg(v) cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << '\n';
#define bit(n, i) ((n>>i)&1)

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        std::vector<int> a(251);
        for(int i=1; i<=250; i++){
            a[i]=i;
        }
        int ans=0;
        int maxx=n*n;
        for(int i=1; i<=n; i++){
           ans+=a[i]*i;
        }
        ans-=maxx;
        for(int i=n-1; i>=1; i--){
            for(int j=1; j<=n; j++){
              a[j]=j;
            }
            int now=n;
            for(int j=i; j<=n; j++){
                a[j]=now;
                now--;
            }
            int sum=0;
            int mx=0;
            for(int j=1; j<=n; j++){
               sum+=a[j]*j;
               mx=max(mx, a[j]*j);
            }
            ans=max(ans, sum-mx);
        }
        cout<<ans<<'\n';
    }
}


