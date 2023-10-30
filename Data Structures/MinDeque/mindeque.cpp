/*
author: mimingucci
created on: 10/30/2023 9:05:47 PM
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

template<class T> struct MinDeque{
   int low=0;
   int high=-1;
   deque<pair<T, int>> d;
   int size(){
   	return high-low+1;
   }	
   void push(T x){
   	while(d.size()>0 && d.back().first>=x)d.pop_back();
   	d.push_back({x, ++high});
   }
   void pop(){
   	assert(size());
   	if(d.front().second==low++)d.pop_front();
   }
   T min(){
   	return size()?d.front().first:DEFAULT;
   }
   //change DEFAULT based on T
};

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */