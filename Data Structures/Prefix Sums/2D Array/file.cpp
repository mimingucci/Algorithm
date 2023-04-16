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
int MAX_N=1e6;
int arr[MAX_N][MAX_N];
int prefix_sum[MAX_N][MAX_N];
int n, m;

//prefix[a][b]= (i=1)∑a (j=1)∑b arr[i][j]
//prefix[i][j]=prefix[i−1][j]+prefix[i][j−1]-prefix[i-1][j-1]+arr[i][j]
void build_prefix_sum(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			prefix_sum[i][j]=prefix_sum[i-1][j]+prefix_sum[i][j-1]-prefix_sum[i-1][j-1]+arr[i][j];
		}
	}
}

//(i=a)∑A (j=b)∑B arr[i][j]=prefix[A][B]-prefix[a-1][B]-prefix[A][b-1]+prefix[a-1][b-1]
int query(int a, int b, int A, int B){
   return prefix_sum[A][B]-prefix_sum[a-1][B]-prefix_sum[A][b-1]+prefix_sum[a-1][b-1];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>arr[i][j];
		}
	}
	build_prefix_sum();

	return 0;
}