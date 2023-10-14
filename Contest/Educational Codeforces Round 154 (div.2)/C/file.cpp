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
      int now=0;
      int maxSortedIndex=0;
      bool isOk=true;
      int n=s.size();
      int avaibleMax=INF;
      for(int i=0; i<n; i++){
        if(s[i]=='+'){
            ++now;
        }else{
            if(s[i]=='-'){
                --now;
                if(now<=avaibleMax){
                    avaibleMax=INF;
                }
                maxSortedIndex=min(maxSortedIndex, now);
            }else{
                if(s[i]=='1'){
                        if(now>avaibleMax){
                            isOk=false;
                            break;
                        }
                        maxSortedIndex=now;
                }else{
                    if(maxSortedIndex==now){
                        isOk=false;
                        break;
                    }
                    avaibleMax=min(now-1, avaibleMax);
                }
            }
        }
        if(now==1 || now==0){
            maxSortedIndex=now;
            avaibleMax=INF;
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