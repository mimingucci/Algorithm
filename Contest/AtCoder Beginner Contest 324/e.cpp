/*
author: mimingucci
created on: 10/14/2023 8:15:02 PM
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
    string t;
    cin>>t;
    int sz=t.size();
    multiset<int> suffix;
    multiset<int> prefix;
    for(int i=0; i<n; i++){
        string x;
        cin>>x;
        int cntSuffix=0;
        int cntPrefix=0;
        int now=0;
        for(int j=0; j<x.size() && now<sz; j++){
            if(x[j]!=t[now])continue;
            ++now;
            ++cntPrefix;
        }
        prefix.insert(cntPrefix);
        now=sz-1;
        for(int j=x.size()-1; j>=0 && now>=0; j--){
            if(x[j]!=t[now])continue;
            --now;
            ++cntSuffix;
        }
        suffix.insert(cntSuffix);
    }
    int ans=0;
    auto cur=prev(suffix.end());
    int now=1;
    for(int i : prefix){
        if((i+*cur)<sz)continue;
        while(cur!=suffix.begin() && i+*prev(cur)>=sz){
            cur=prev(cur);
            ++now;
        }
        ans+=now;
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