#include <bits/stdc++.h>
using namespace std;
const int64_t MAXN=200001;

struct Node{
	int64_t g_max, l_max, r_max, sum;
    Node operator+ (Node b) {
		return {max(max(g_max, b.g_max), r_max + b.l_max),
		        max(l_max, sum + b.l_max), max(b.r_max, r_max + b.sum),
		        sum + b.sum};
	}
};

int64_t n, a[MAXN];
Node segtree[4*MAXN];

void build(int64_t node, int64_t l, int64_t r){
	if(l==r){
		segtree[node]={max(a[l], int64_t(0)), a[l], a[r], a[l]};
	}else{
		int64_t mid = l + r >> 1;
		build(2*node, l, mid);
		build(2*node+1, mid+1, r);
		segtree[node]=segtree[2*node]+segtree[2*node+1];
	}
}

void update(int64_t pos, int64_t val, int64_t node, int64_t l, int64_t r){
    if(l==r){
    	segtree[node]={max(val, int64_t(0)), val, val, val};
    }else{
    	int64_t mid = l + r >> 1;
    	if(mid>=pos){
    		update(pos, val, 2*node, l, mid);
    	}else{
    		update(pos, val, 2*node+1, mid+1, r);
    	}
    	segtree[node]=segtree[2*node]+segtree[2*node+1];
    }
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    int m;
    cin>>m;
    for(int64_t i=1; i<=n; i++)cin>>a[i];
    build(1, 1, n);
    while(m--){
    	int64_t x, y;
    	cin>>x>>y;
    	update(x, y, 1, 1, n);
    	cout<<segtree[1].g_max<<'\n';
    }	
	return 0;
}