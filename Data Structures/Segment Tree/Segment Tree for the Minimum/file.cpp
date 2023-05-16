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

struct segment_tree{
    int size;
    std::vector<int> val;

    void init(int n){
    	size=1;
    	while(size<n){
    		size=size*2;
    	}
    	val.assign(2*size, INT_MAX);
    }

    void build(std::vector<int> v, int x, int lx, int rx){
    	if(rx-lx==1){
    		if(lx<(int)v.size()){
    			val[x]=v[lx];
    		}
    		return;
    	}
    	int m=(lx+rx)/2;
    	build(v, 2*x+1, lx, m);
    	build(v, 2*x+2, m, rx);
    	val[x]=min(val[2*x+1], val[2*x+2]);
    }

    void build(std::vector<int> v){
    	build(v, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx){
    	if(rx-lx==1){
    		val[x]=v;
    		return;
    	}
    	int m=(lx+rx)/2;
    	if(i<m){
    		set(i, v, 2*x+1, lx, m);
    	}else{
    		set(i, v, 2*x+2, m, rx);
    	}
    	val[x]=min(val[2*x+1], val[2*x+2]);
    }

    void set(int i, int v){
       set(i, v, 0, 0, size);
    }

    int calc(int l, int r, int x, int lx, int rx){
    	if(lx>=r || rx<=l)return INT_MAX;
    	if(lx>=l && rx<=r)return val[x];
    	int m=(lx+rx)/2;
    	int first=calc(l, r, 2*x+1, lx, m);
    	int second=calc(l, r, 2*x+2, m, rx);
    	return min(first, second);
    }

    int calc(int l, int r){
    	return calc(l, r, 0, 0, size);
    }
   
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    segment_tree segment;
    std::vector<int> v(n);
    segment.init(n);
    for(int i=0; i<n; i++){
    	cin>>v[i];
    }
    segment.build(v);
    while(m--){
    	int t;
    	cin>>t;
    	if(t==1){
    		int i;
    		int v;
    		cin>>i>>v;
    		segment.set(i, v);
    	}else{
    		int l, r;
    		cin>>l>>r;
    		cout<<segment.calc(l, r)<<'\n';
    	}
    }
	return 0;
}