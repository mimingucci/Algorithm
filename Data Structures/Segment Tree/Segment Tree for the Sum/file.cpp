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
    std::vector<int64_t> sums;

    void init(int n){
    	size=1;
    	while(size<n){
    		size=size*2;
    	}
    	sums.assign(2*size, 0);
    }

    void build(std::vector<int64_t> v, int x, int lx, int rx){
    	if(rx-lx==1){
    		if(lx<(int)v.size()){
    			sums[x]=v[lx];
    		}
    		return;
    	}
    	int m=(lx+rx)/2;
    	build(v, 2*x+1, lx, m);
    	build(v, 2*x+2, m, rx);
    	sums[x]=sums[2*x+1]+sums[2*x+2];
    }

    void build(std::vector<int64_t> v){
    	build(v, 0, 0, size);
    }

    void set(int i, int64_t v, int x, int lx, int rx){
    	if(rx-lx==1){
    		sums[x]=v;
    		return;
    	}
    	int m=(lx+rx)/2;
    	if(i<m){
    		set(i, v, 2*x+1, lx, m);
    	}else{
    		set(i, v, 2*x+2, m, rx);
    	}
    	sums[x]=sums[2*x+1]+sums[2*x+2];
    }

    void set(int i, int64_t v){
       set(i, v, 0, 0, size);
    }

    int64_t sum(int l, int r, int x, int lx, int rx){
    	if(lx>=r || rx<=l)return 0;
    	if(lx>=l && rx<=r)return sums[x];
    	int m=(lx+rx)/2;
    	int64_t first=sum(l, r, 2*x+1, lx, m);
    	int64_t second=sum(l, r, 2*x+2, m, rx);
    	return first+second;
    }

    int64_t sum(int l, int r){
    	return sum(l, r, 0, 0, size);
    }
   
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    segment_tree segment;
    std::vector<int64_t> v(n);
    segment.init(n);
    for(int i=0; i<m; i++){
    	// int64_t v;
    	// cin>>v;
    	// segment.set(i, v);
    	cin>>v[i];
    }
    segment.build(v);
    while(m--){
    	int t;
    	cin>>t;
    	if(t==1){
    		int i;
    		int64_t v;
    		cin>>i>>v;
    		segment.set(i, v);
    	}else{
    		int l, r;
    		cin>>l>>r;
    		cout<<segment.sum(l, r)<<'\n';
    	}
    }
	return 0;
}