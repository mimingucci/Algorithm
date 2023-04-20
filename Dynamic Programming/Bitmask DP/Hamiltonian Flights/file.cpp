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
    ii n, m;
    cin>>n>>m;
    vector<pair<ii, ii>> data(m);
    vector<ii> come_from[20];
    for(ii i=0; i<m; i++){
    	ii from, to;
    	cin>>from>>to;
    	come_from[to-1].push_back(from-1);
    }
    ii f[1<<n][n];
    fill(*f, *f+(1<<n)*n, 0);
    f[1][0]=1;
    for(ii i=2; i<(1<<n); i++){
    	if((i & (1<<0))==0)continue;
    	if((i & (1<<(n-1))) && i!=((1<<n)-1))continue;
    	for(ii j=0; j<n; j++){
            if((i & (1<<j))==0)continue;
            il p=i^(1<<j);
            for(ii k : come_from[j]){
            	if(i & (1<<k)){
            		f[i][j]+=f[p][k];
            		f[i][j]%=1000000007;
            	}
            }
    	}
    }
    cout<<f[(1<<n)-1][n-1];
	return 0;
}