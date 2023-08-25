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
       int n;
       cin>>n;
       std::vector<int> a(n);
       input(a);
       std::vector<int> ans;
       ans.push_back(a[0]);
       for(int i=1; i<n; i++){
        if(a[i]>=a[i-1]){
            ans.push_back(a[i]);
        }else{
            ans.push_back(1);
            ans.push_back(a[i]);
        }
       }
       cout<<ans.size()<<'\n';
       output(ans);
       cout<<'\n';
    }
}