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
const int INF=(int)1<<62;
const int MAXN=1e5;


main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
      string s;
      cin>>s;
      string ans="";
      for(int i=0; i<s.size(); i++){
        if(s[i]=='1' || s[i]=='3'){
            ans+=s[i];
        }
      }
      cout<<ans<<'\n';
    } 
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */