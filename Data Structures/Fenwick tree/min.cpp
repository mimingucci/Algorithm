/*
author: mimingucci
created on: 10/31/2023 9:07:47 AM
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
const int INF=(int)1<<62;
const int MAXN= 1e6;

struct FenwickTree{
    std::vector<int> bit;
    int n;
    FenwickTree(int n){
    	this->n=n;
    	bit.assign(n, INF);
    }
    FenwickTree(std::vector<int> a):FenwickTree(a.size()){
    	for(int i=0; i<n; i++){
    		bit[i]=min(bit[i], a[i]);
    		int r=i|(i+1);
    		if(r<n)bit[r]=min(bit[r], bit[i]);
    	}
    }
    int getmin(int r){
    	int res=INF;
    	for(; r>=0; r=(r&(r+1))-1){
    		res=min(res, bit[r]);
    	}
    	return res;
    }
    void update(int idx, int value){
    	for(; idx<n; idx=idx|(idx+1)){
    		bit[idx]=min(bit[idx], value);
    	}
    }
};

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    std::vector<int> a{1, -2, 7, 4, 11, -2, 0, 5};
    FenwickTree bit(a);
    cout<<bit.getmin(7)<<'\n';
    bit.update(1, -4);
    cout<<bit.getmin(4)<<'\n';
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */