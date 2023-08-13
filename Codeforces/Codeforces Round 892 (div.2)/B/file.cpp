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
        std::vector<pair<int, int>> a;
        for(int j=0; j<n; j++){
           int s;
           cin>>s;
           multiset<int> sett;
           for(int i=0; i<s; i++){
            int x;
            cin>>x;
            sett.insert(x);
           }
           auto it=sett.begin();
           int f=*it;
           it=next(it);
           int sc=*it;
           a.push_back({sc, f});
        }
        sort(a);
        int ans=0;
        set<int> minn;
        minn.insert(a[0].first);
        minn.insert(a[0].second);
        for(int i=n-1; i>=1; i--){
            ans+=a[i].first;
            minn.insert(a[i].second);
        }
        ans+=*minn.begin();
        cout<<ans<<'\n';
    }
}


