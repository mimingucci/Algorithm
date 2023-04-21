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
struct DSU{
	vector<int> e;
	DSU(int n){
		e=vector<int> (n, -1);
	}
	int get(int x){
		return e[x]<0? x : e[x]=get(e[x]);
	}
	bool same_set(int a, int b){
		return get(a)==get(b);
	}
	int size(int x){
		return -e[get(x)];
	}

	bool unite(int a, int b){
		a=get(a);
		b=get(b);
		if(a==b){
			return false;
		}
		if(size(a)>size(b)){
			swap(a, b);
		}
		e[a]+=e[b];
		e[b]=a;
		return true;
	}
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, q;
    cin>>n>>q;
    DSU dsu=DSU(n);
    for(int i=0; i<q; i++){
    	int t, u, v;
    	cin>>t>>u>>v;
    	if(t==0){
    		dsu.unite(u, v);
    	}else{
    		if(dsu.same_set(u, v)){
    			cout<<1<<'\n';
    		}else{
    			cout<<0<<'\n';
    		}
    	}
    }
	return 0;
}

//Link problem: https://judge.yosupo.jp/problem/unionfind