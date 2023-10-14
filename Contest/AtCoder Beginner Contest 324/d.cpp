/*
author: mimingucci
created on: 10/14/2023 8:51:43 PM
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
    string s;
    cin>>s;
    sort(begin(s), end(s));
    int ans=0;
    for(int i=0; i*i<=pow(10, n); i++){
        string t=to_string(i*i);
        t.resize(n, '0');
        sort(begin(t), end(t));
        if(t==s){
            ++ans;
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