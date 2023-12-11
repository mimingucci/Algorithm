/*
author: mimingucci
created on: 12/11/2023 1:38:11 PM
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
    int n;
    cin>>n;
    FenwickTree bit(MAXN);
    set<int> s;
    std::map<int, std::vector<int>> st;
    std::map<int, std::vector<int>> en;
    map<int, std::vector<pair<int, int>>> verticals;
    for(int i=0; i<n; i++){
        int type;
        cin>>type;
        if(type==1){
        	int x1, x2, y;
        	cin>>x1>>x2>>y;
        	st[x1].push_back(y);
        	st[x2].push_back(y);
        	s.insert(x1);
        	s.insert(x2);
        }else{
        	int x, y1, y2;
        	cin>>x>>y1>>y2;
        	if(y1>y2)swap(y1, y2);
        	verticals[x].push_back({y1, y2});
        	s.insert(x);
        }
    }
    int ans=0;
    for(int i : s){
    	for(int j : st[i]){
    		bit.add(j, 1);
    	}
        for(auto [x, y] : verticals[i]){
        	ans+=bit.sum(x, y);
        }
        for(int j : en[i]){
        	bit.add(j, -1);
        }
    }
    cout<<ans;
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */