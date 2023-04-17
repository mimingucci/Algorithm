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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(false);
	ii n, x;
	cin>>n>>x;
	ii a[n+1];
	a[0]=0;
	for(ii i=1; i<=n; i++)cin>>a[i];
	ii b[n+1];
    copy(begin(a), end(a), begin(b));
    sort(b);
    ii l=1, r=n;

    while(r>l){
       if(b[l]+b[r]==x){
       	break;
       }else{
       	if(b[l]+b[r]>x){
       		--r;
       	}else{
       		++l;
       	}
       }
    }
    if(l==r || b[l]+b[r]!=x){
    	cout<<"IMPOSSIBLE";
    }else{
    	cout<<find(begin(a), end(a), b[l])-a.begin()<<" "<<find(begin(a), end(a), b[r])-a.begin();
    }
	return 0;
}
