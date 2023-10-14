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
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        std::vector<std::array<int, 2>> v(n);
        for(int i=0; i<n; i++){
            int l, r, a, b;
            cin>>l>>r>>a>>b;
            v[i][0]=l;
            v[i][1]=b;
        }
        sort(v);
        std::vector<std::array<int, 2>> a;
        for(int i=0; i<n; i++){
           if(a.size()>0 && v[i][0]<=a.back()[1]){
             a.back()[1]=max(a.back()[1], v[i][1]);
           }else{
             a.push_back(v[i]);
           }
        }
        int q;
        cin>>q;
        while(q--){
            int x;
            cin>>x;
            int index=lower_bound(a.begin(), a.end(), array{x+1, (int)0})-a.begin()-1;
            if(index>=0){
                x=max(x, a[index][1]);
            }
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}


