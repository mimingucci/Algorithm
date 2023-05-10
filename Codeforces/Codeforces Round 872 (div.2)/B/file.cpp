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
        int64_t n, m;
        cin>>n>>m;
        std::vector<int64_t> v(n*m);
        for(int64_t i=0; i<n*m; i++){
            cin>>v[i];
        }
        sort(v);
        int64_t a=(m-1)*(v.back()-v[1])+(v.back()-v[0])*(n-1)*m;
        int64_t b=(n-1)*(v.back()-v[1])+(v.back()-v[0])*(n*m-n);
        int64_t c=(m-1)*(v[n*m-2]-v[0])+(n-1)*m*(v[n*m-1]-v[0]);
        int64_t d=(n-1)*(v[n*m-2]-v[0])+(m-1)*n*(v.back()-v[0]);
        cout<<max(a, max(b, max(c, d)))<<'\n';
    }
    return 0;    
}