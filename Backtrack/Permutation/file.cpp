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
// list all permutation of 1...n
int n;
bool used[1000000];
int a[1000000];
void show(){
	for(int i=1; i<=n; i++){
		cout<<a[i]<<" ";
	}
	cout<<'\n';
}
void backtracking(int s){
	if(s>n){
		show();
		return;
	}
	for(int i=1; i<=n; i++){
		if(!used[i]){
			a[s]=i;
			used[i]=true;
			backtracking(s+1);
			used[i]=false;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cin>>n;
    fill(used, used+1000000, false);
    backtracking(1);
	return 0;
}