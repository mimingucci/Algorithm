/*
author: mimingucci
created on: 11/4/2023 7:08:40 PM
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

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int a[10][10];
    for(int i=1; i<=9; i++){
    	for(int j=1; j<=9; j++){
    		cin>>a[i][j];
    	}
    }
    bool isOk=true;
    for(int i=1; i<=9; i++){
    	set<int> s;
    	for(int j=1; j<=9; j++){
           s.insert(a[i][j]);
    	}
    	if(s.size()<9)isOk=false;
    }
    for(int i=1; i<=9; i++){
    	set<int> s;
    	for(int j=1; j<=9; j++){
           s.insert(a[j][i]);
    	}
    	if(s.size()<9)isOk=false;
    }
    for(int i=1; i<=9; i+=3){
    	for(int j=1; j<=9; j+=3){
    		set<int> s;
    		for(int k=i; k<=i+2; k++){
    			for(int h=j; h<=j+2; h++){
    				s.insert(a[k][h]);
    			}
    		}
    		if(s.size()<9)isOk=false;
    	}
    }
    if(isOk){
    	cout<<"Yes";
    }else{
    	cout<<"No";
    }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */