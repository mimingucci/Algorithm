/*
author: mimingucci
created on: 10/14/2023 7:01:11 PM
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
    std::vector<int> a(n);
    for(int i=0; i<n; i++)cin>>a[i];
    bool isOk=true;
    for(int i=1; i<n; i++){
        if(a[i]!=a[i-1])isOk=false;
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