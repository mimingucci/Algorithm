#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define vdl vector<double long>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vpil vector<pair<int, long long>>
#define vpli vector<pair<long long, int>>
#define ii int64_t
#define sort(A) sort(A.begin(), A.end())
#define input(A) for(auto &x : A)cin>>x
#define output(A) for(auto &x : A)cout<<x<<" "
#define dbg(v) cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << '\n';
#define bit(n, i) ((n>>i)&1)
int main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int64_t n, x;
        cin>>n>>x;
        std::vector<int64_t> v(n+1);
        for(int64_t i=1; i<=n; i++){
            cin>>v[i];
        }
        v[0]=0;
        int64_t pivot=-1;
        sort(v);
        bool isOk=false;
        std::vector<int64_t> u(n+1, 0);
        for(int64_t i=1; i<=n; i++){
            u[i]=u[i-1]+v[i];
            if(u[i]>x){
                pivot=i-1;
                isOk=true;
                break;
            }
        }
        if(!isOk){
            pivot=n;
        }
        if(pivot<=0){
            cout<<0<<'\n';
            continue;
        }
        int64_t res=pivot;
        for(int64_t i=pivot; i>=1; i--){
            int64_t cnt=(x-u[i])/i;
            if(i==pivot){
                res+=cnt*i;
            }else{
                res+=i*max((cnt-(x-u[i+1])/(i+1)), (int64_t) 0);
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}