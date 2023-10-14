/*
author: mimingucci
created on: 10/14/2023 7:03:10 PM
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
    int n;
    cin>>n;
    bool isOk=true;
    while(n%2==0){
        n/=2;
    }
    while(n%3==0){
        n/=3;
    }
    if(n>1){
        cout<<"No";
    }else{
        cout<<"Yes";
    }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */