/*
author: mimingucci
created on: 2/8/2024 7:48:24 PM
*/
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
const int INF=(int)1<<62;
const int MAXN= 5*1e5+7;

//link: https://atcoder.jp/contests/abc339/tasks/abc339_e

int op(int a, int b) { return max(a, b); }

int e() { return 0; }

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int n, d;
    cin>>n>>d;
    std::vector<int> a(n);
    for(int &i : a)cin>>i;
    segtree<int, op, e> st(MAXN);
    for(int i : a){
    	int l=max(int(1), i-d);
    	int r=min(MAXN, i+d+1);
    	st.set(i, 1+st.prod(l, r));
    }	
    cout<<st.all_prod()<<endl;
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */