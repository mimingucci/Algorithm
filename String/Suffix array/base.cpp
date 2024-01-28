/*
author: mimingucci
created on: 1/22/2024 11:57:56 PM
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
    string s;
    cin>>s;
    s+="$";
    int n=s.size();
    std::vector<int> p(n), c(n);
    std::vector<pair<char, int>> a(n);
    for(int i=0; i<n; i++)a[i]={s[i], i};
    sort(begin(a), end(a));
    for(int i=0; i<n; i++)p[i]=a[i].second;
    c[p[0]]=0;
    for(int i=1; i<n; i++){
        if(a[i].first==a[i-1].first){
            c[p[i]]=c[p[i-1]];
        }else{
            c[p[i]]=c[p[i-1]]+1;
        }
    }    
    int k=0;
    while((1<<k)<n){
        //k->k+1
        std::vector<pair<pair<int, int>, int>> v(n);
        for(int i=0; i<n; i++){
            v[i]={{c[i], c[(i+(1<<k))%n]}, i};
        }
        sort(begin(v), end(v));
        for(int i=0; i<n; i++){
            p[i]=v[i].second;
        }
        c[p[0]]=0;
        for(int i=1; i<n; i++){
            if(v[i].first==v[i-1].first){
                c[p[i]]=c[p[i-1]];
            }else{
                c[p[i]]=c[p[i-1]]+1;
            }
        }
        ++k;
    }
    for(int i=0; i<n; i++){
        cout<<p[i]<<" ";
    }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */