/*
author: mimingucci
created on: 10/31/2023 11:19:24 AM
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
    std::vector<std::vector<int>> bit;
    int n, m;
    FenwickTree(int n, int m){
    	this->n=n+1;
    	this->m=m+1;
    	bit.assign(n+1, std::vector<int> (m+1, 0));
    }
    FenwickTree(std::vector<std::vector<int>> a):FenwickTree(a.size(), a.front().size()){
    	for(int i=0; i<a.size(); i++){
    		for(int j=0; j<a.front().size(); j++){
    			add(i, j, a[i][j]);
    		}
    	}
    }
    void add(int x, int y, int value){
    	for(int i=x+1; i<n; i=i+(i&(-i))){
    		for(int j=y+1; j<m; j=j+(j&(-j))){
    			bit[i][j]+=value;
    		}
    	}
    }
    int sum(int x, int y){
    	int res=0;
    	for(int i=x; i>0; i=i-(i&(-i))){
    		for(int j=y; j>0; j=j-(j&(-j))){
    			res+=bit[i][j];
    		}
    	}
    	return res;
    }
    int sum(int x1, int y1, int x2, int y2){
        return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
    }
};

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    std::vector<std::vector<int>> a{{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    FenwickTree bit(a);
    cout<<bit.sum(3, 2, 3, 3);
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */