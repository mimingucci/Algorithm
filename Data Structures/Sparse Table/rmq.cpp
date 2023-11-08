/*
author: mimingucci
created on: 11/9/2023 12:10:21 AM
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
// C++20
// int log2_floor(unsigned long long i) {
//     return std::bit_width(i) - 1;
// }

// pre C++20
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
int sparse_table(std::vector<int> a, int l, int r){
    int n=a.size();
    int logn=log2_floor(n);
    std::vector<std::vector<int>> m(n, std::vector<int> (logn+1, 0));
    for(int i=0; i<n; i++){
    	m[i][0]=i;
    }
    for(int j=1; (1<<j)<=n; j++){
    	for(int i=0; i+(1<<j)-1<n; i++){
           if(a[m[i][j-1]]<=a[m[i+(1<<(j-1))][j-1]]){
           	 m[i][j]=m[i][j-1];
           }else{
           	 m[i][j]=m[i+(1<<(j-1))][j-1];
           } 
    	}
    }
    int idx=-1;
    int value=INF;
    for(int i=logn; i>=0; i--){
    	if((1<<i)<=r-l+1){
    		if(a[m[l][i]]<value){
    			idx=m[l][i];
    			value=a[m[l][i]];
    		}
            l+=(1<<i);
    	}
    }
    return idx;
}

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    std::vector<int> a{2, 4, 3, 1, 6, 7, 8, 9, 1, 7};
    cout<<sparse_table(a, 7, 9);
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */