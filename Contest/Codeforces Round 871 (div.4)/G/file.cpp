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
int64_t grid[1500][1500];
int64_t cnt=1;
int64_t ans[1000007];


int main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    fill(*grid, *grid+1500*1500, 0);
    for(int64_t i=1; i<1500; i++){
        for(int64_t j=i-1; j>=1; j--){
            grid[j][i-j]=grid[j-1][i-j]+grid[j][i-j-1]-grid[j-1][i-j-1]+cnt*cnt;
            ans[cnt++]=grid[j][i-j];
        }
    }
    int t;
    cin>>t;
    while(t--){
        int64_t n;
        cin>>n;
        cout<<ans[n]<<'\n';
    }
    
    return 0;    
}

