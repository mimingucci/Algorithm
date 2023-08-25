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
        int n, m, d;
        cin>>n>>m>>d;
        vector<int> a(n);
        input(a);
        multiset<int> sett;
        int sum = 0;
        int ans = -100000000000;
        for (int i = 0; i < n; i++) {
            if (a[i]>0){
                sum += a[i];
                sett.insert(a[i]);
                if ((int)sett.size()>m) {
                    sum -= *sett.begin();
                    sett.erase(sett.begin());
                }
                ans = max(sum - (i + 1)*d, ans);
           }
        } 
        cout<<max(ans, (int)0)<< "\n";  
    } 
}