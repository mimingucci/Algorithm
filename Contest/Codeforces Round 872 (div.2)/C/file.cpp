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
        int n, m;
        cin>>n>>m;
        int cntFirst=0;
        int cntSecond=0;
        set<int> sett;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            if(x==-1){
                ++cntFirst;
            }else{
                if(x==-2){
                    ++cntSecond;
                }else{
                    sett.insert(x);
                }
            }
        }
        int left=0;
        int res=min(m, max(cntFirst+(int)sett.size(), cntSecond+(int)sett.size()));
        for(int i : sett){
            res=max(res, 1+min(i-1, cntFirst+left)+min(m-i, cntSecond+(int)sett.size()-left-1));
            ++left;
        }
        cout<<res<<'\n';
    }
 
    return 0;    
}