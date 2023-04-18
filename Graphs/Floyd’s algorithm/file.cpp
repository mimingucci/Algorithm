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
	cin.tie(nullptr);
	int n;
	cin>>n;
	int succ[n+1];
	for(int i=1; i<=n; i++){
		int a, b;
		cin>>a>>b;
		succ[a]=b;
	}
	//walks forward in the graph using two pointers a and b.
//Both pointers begin at a node x that is the starting node of the graph. Then,
//on each turn, the pointer a walks one step forward and the pointer b walks two
//steps forward. The process continues until the pointers meet each other
	int a, b;
	a=succ[1];
	b=succ[succ[1]];
	while(a!=b){
		a=succ[a];
		b=succ[succ[b]];
	}
	// the first node that belongs
//to the cycle can be found by moving the pointer a to node x and advancing the
//pointers step by step until they meet again
	a=1;
	while(a!=b){
		a=succ[a];
		b=succ[b];
	}
	int first=a;
	//the length of the cycle can be calculated as follows
	b=succ[a];
	int length=1;
	while(a!=b){
		b=succ[b];
		++length;
	}
	//let call succ(x, k) is successsor we reach from node x after k step forward. It take O(k) time
	//calculate succ(x, k) in O(log(k)) time
	//succ(x, k)=succ[x] if k=1, =succ(succ(x, k/2), k/2) if k>1
	//after that, f succ(x,k) can be calculated by presenting the number
    //of steps k as a sum of powers of two e.g : 11 = 8 + 2 +1 succ(x, 11)=succ(succ(succ(x, 8), 2), 1)

	return 0;
}