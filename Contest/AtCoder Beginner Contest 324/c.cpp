/*
author: mimingucci
created on: 10/14/2023 7:08:08 PM
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
    string tp;
    cin>>tp;
    int sz=tp.size();
    std::vector<int> ans;
    for(int i=1; i<=n; i++){
        string t;
        cin>>t;
        int szz=t.size();
        if(abs(szz-sz)>=2){
            continue;
        }
        if(szz==sz){
           int diff=0;
           for(int j=0; j<sz; j++){
            if(tp[j]==t[j])continue;
            ++diff;
           }
           if(diff<2){
            ans.push_back(i);
           }
        }else{
           int diff=0; 
           if(sz>szz){
             for(int j=0; j<szz && diff<2; j++){
                if(t[j]!=tp[j+diff]){
                    ++diff;
                    if(diff>=2)break;
                    if(t[j]!=tp[j+diff]){
                        diff++;
                        break;
                    }
                }
             }
             if(diff<2){
                ans.push_back(i);
             }
           }else{
             for(int j=0; j<sz && diff<2; j++){
                if(t[j+diff]!=tp[j]){
                    ++diff;          
                    if(diff>=2)break;
                    if(t[j+diff]!=tp[j]){
                        ++diff;
                    }      
                }
             }
             if(diff<2){
                ans.push_back(i);
             }
           }
        }
    }
    cout<<ans.size()<<'\n';
    for(int i : ans){
        cout<<i<<" ";
    }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */