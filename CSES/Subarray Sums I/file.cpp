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
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ii n, x;
    cin>>n>>x;
    vector<ii> a(n+1);
    ii subsum=0;
    for(ii i=1; i<=n; i++){
        cin>>a[i];
    }
    ii cnt=0;
    ii l=1; ii r=1;
    subsum=a[1];
    while(l<=n && r<=n){
       if(subsum==x){
        ++cnt;
        if(r==n){
            break;
        }else{
            ++r;
            subsum+=a[r];
        }
       }else{
        if(subsum>x){
            subsum-=a[l];
            ++l;
        }else{
            ++r;
            subsum+=a[r];
        }
       }
    }
    cout<<cnt;
	return 0;
}