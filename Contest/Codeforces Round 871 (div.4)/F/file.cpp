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
       map<int64_t, int64_t> a;
       int64_t cntOne=0;
       for(int64_t i=0; i<m; i++){
        int64_t x, y;
        cin>>x>>y;
        a[x]++;
        a[y]++;
        if(a[x]==1){
            ++cntOne;
        }else{
            if(a[x]==2){
                --cntOne;
            }
        }
        if(a[y]==1){
            ++cntOne;
        }else{
            if(a[y]==2)
            --cntOne;
        }
       }
       cout<<n-cntOne-1<<" "<<cntOne/(n-cntOne-1)<<'\n';

    }
    return 0;    
}



