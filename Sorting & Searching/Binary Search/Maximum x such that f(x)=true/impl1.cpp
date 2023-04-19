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
int last_true(int lo, int hi, function<bool(int)> f){
	lo--;
	while(lo<hi){
		int mid=lo+(hi-lo+1)/2;
		if(f(mid)){
			lo=mid;
		}else{
			hi=lo-1;
		}
	}
	return lo;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    cout<<last_true(2, 10, [](int x){return true;});
	return 0;
}