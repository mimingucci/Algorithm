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
vll prefix_sum(const vll &a){
	vll ps((int)a.size()+1);
    partial_sum(begin(a), end(a), begin(ps)+1);
    return ps;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    cin>>n;
    vll a(n);
    input(a);
    vll ps=prefix_sum(a);
    for(int i=1; i<=n; i++){
    	cout<<ps[i]<<" ";
    }
	return 0;
}