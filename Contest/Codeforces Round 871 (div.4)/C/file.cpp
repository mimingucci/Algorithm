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
    int w;
    cin>>w;
    while(w--){
       int n;
       cin>>n;
       int64_t zeroone=1e9;
       int64_t onezero=1e9;
       int64_t oneone=1e9;
       while(n--){
        int64_t t;
        string s;
        cin>>t>>s;
        if(s=="00"){
            continue;
        }else{
            if(s=="01"){
                zeroone=min(zeroone, t);
            }
            if(s=="10"){
                onezero=min(onezero, t);
            }
            if(s=="11"){
                oneone=min(oneone, t);
            }
        }
       }
       if(min(zeroone+onezero, oneone)>=1e9){
        cout<<-1<<'\n';
        continue;
       }
       cout<<min(zeroone+onezero, oneone)<<'\n';
    }
    return 0;    
}