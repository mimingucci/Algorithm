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
       std::vector<int> a(n+1);
       for(int i=1; i<=n; i++)cin>>a[i]; 
       bool isOk=true;
       for(int i=1; i<=n; i++){
          if(a[i]>n){
            isOk=false;
            break;
          } 
          if(a[a[i]]>=i){
            if(a[i]==n){
               continue;
            }else{
                if(a[i]+1>n){
                    isOk=false;
                    break;
                }
                if(a[a[i]+1]>=i){
                    isOk=false;
                    break;
                }else{
                    continue;
                }
            }
          }else{
            isOk=false;
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