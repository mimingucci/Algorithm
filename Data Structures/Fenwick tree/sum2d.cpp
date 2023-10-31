/*
author: mimingucci
created on: 10/31/2023 9:31:25 AM
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
	    this->n=n;
        this->m=m;
        bit.assign(n, std::vector<int> (m, 0));
	}
	FenwickTree(std::vector<std::vector<int>> a):FenwickTree(a.size(), a.front().size()){
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		add(i, j, a[i][j]);
        	}
        }
	}
	int sum(int x, int y){
		int res=0;
		for(int i=x; i>=0; i=(i&(i+1))-1){
			for(int j=y; j>=0; j=(j&(j+1))-1){
				res+=bit[i][j];
			}
		}
		return res;
	}
	void add(int x, int y, int value){
		for(int i=x; i<n; i=i|(i+1)){
			for(int j=y; j<m; j=j|(j+1)){
				bit[i][j]+=value;
			}
		}
	}
};

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    std::vector<std::vector<int>> a{{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    FenwickTree bit(a);
    cout<<bit.sum(2, 1);
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
