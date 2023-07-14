#include <bits/stdc++.h>
using namespace std;

const int MAXN=200001;

int n;
long long segtree[4*MAXN], a[MAXN];

void build(int node, int l, int r){
	if(l==r){
		segtree[node]=a[l];
	}else{
		int mid = l + r >> 1;
		build(2*node, l, mid);
		build(2*node + 1, mid+1, r);
		segtree[node]=max(segtree[2*node], segtree[2*node+1]);
	}
}

void queryupdate(int node, int l, int r, long long val){
	if(l==r){
		segtree[node]-=val;
		cout << l << " ";
	}else{
		int mid = l + r >> 1;
		if(segtree[2*node]>=val){
		  queryupdate(2*node, l, mid, val);
		}else{
		  queryupdate(2*node+1, mid+1 , r, val);	
		}
		segtree[node]=max(segtree[2*node], segtree[2*node+1]);
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    int m;
    cin>>m;
    for(int i=1; i<=n; i++)cin>>a[i];
    build(1, 1, n);
    while(m--){
    	long long x;
    	cin>>x;
    	if(segtree[1]<x){
    		cout<<"0 ";
    	}else{
    		queryupdate(1, 1, n, x);
    	}
    }	
	return 0;
}