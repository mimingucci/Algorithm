/*
author: mimingucci
created on: 1/4/2024 9:07:50 PM
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

//link: https://codeforces.com/contest/1895/problem/D 

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    std::vector<int> a(n);
    for(int i=1; i<n; i++){
        cin>>a[i];
        a[i]^=a[i-1];
    }
    std::vector<std::vector<int>> trie;
    trie.push_back({-1, -1});
    auto add=[&](int x)->void{
       int now=0;
       for(int i=20; i>=0; i--){
         int j=(x>>i)&1;
         if(trie[now][j]==-1){
            trie[now][j]=trie.size();
            trie.push_back({-1, -1});
         }
         now=trie[now][j];
       }
    };
    auto get=[&](int x)->int{
       int now=0;
       for(int i=20; i>=0; i--){
         int j=(x>>i)&1;
         if(trie[now][j^1]!=-1){
            j^=1;
         }
         x=x^(j<<i);
         now=trie[now][j];
       }
       return x;
    };
    for(int i : a)add(i);
    for(int i : a){
        if(get(i)==n-1){
            for(int j : a){
                cout<<(j^i)<<" ";
            }
            break;
        }
    }    
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */