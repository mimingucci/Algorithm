/*
author: mimingucci
created on: 10/31/2023 10:13:19 AM
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
    	this->n=n+1;
    	bit.assign(n+1, 0);
    }
    FenwickTree(std::vector<int> a):FenwickTree(a.size()){
    	for(int i=0; i<a.size(); i++){
    		add(i, a[i]);
    	}
    }
    void add(int idx, int value){
    	for(++idx; idx<n; idx+=idx&(-idx)){
    		bit[idx]+=value;
    	}
    }
    int sum(int r){
    	int res=0;
    	for(++r; r>0; r-=r&(-r)){
    		res+=bit[r];
    	}
    	return res;
    }
    int sum(int l, int r){
        return sum(r)-sum(l-1);
    }
};

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    std::vector<int> a{1, -2, 7, 4, 11, -2, 0, 5};
    FenwickTree bit(a);
    cout<<bit.sum(0, 3);
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */