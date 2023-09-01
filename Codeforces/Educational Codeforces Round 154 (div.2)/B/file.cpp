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
      string a, b;
      cin>>a>>b;
      if(a==b){
        cout<<"YES\n";
        continue;
      }
      set<int> a1, a0, b1, b0;
      int n=a.size();
      for(int i=1; i<n-1; i++){
        if(a[i]=='0' && a[i+1]=='1'){
            a0.insert(i);
        }
        if(b[i]=='0' && b[i+1]=='1'){
            b0.insert(i);
        }
      }
      for(int i=n-2; i>0;  i--){
        if(a[i]=='1' && a[i-1]=='0'){
            a1.insert(i);
        }
        if(b[i]=='1' && b[i-1]=='0'){
            b1.insert(i);
        }
      }
      bool isOk=false;
      for(int i : a0){
        if(b0.count(i)>0){
            isOk=true;
            break;
        }
      }
      for(int i : a1){
        if(b1.count(i)>0){
            isOk=true;
            break;
        }
      }
      if(isOk){
        cout<<"YES\n";
      }else{
        cout<<"NO\n";
      }
    } 
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */