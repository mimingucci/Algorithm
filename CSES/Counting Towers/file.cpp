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
const ii mod=1e9+7;
 
int main()
{ 
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ii t;
    cin>>t;
    while(t--){
    	ii n;
    	cin>>n;
    	ii a[n+1];
    	ii b[n+1];
    	a[1]=1;
    	b[1]=1;
    	ii i=1; 
    	ii j=1;
    	while(i<=n && j<=n){
    		if(i==j){
    			++i;
    			a[i]=2*a[i-1]+b[i-1];
    			a[i]%=mod;
    		}else{
    			++j;
    			b[j]=4*b[j-1]+a[j-1];
    			b[j]%=mod;
    		}
    		
    	}
    	cout<<(a[n]+b[n])%mod<<'\n';
    }
	return 0;
}