/*
author: mimingucci
created on: 1/29/2024 12:00:26 AM
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
const int MOD=(int)1<<31;
const int mod=1e9+7;

//link: https://community.topcoder.com/stat?c=problem_statement&pm=17876

struct DSU{
    vector<int> e;
    std::vector<int> sz;
    DSU(int n){
        e=vector<int> (n, -1);
        sz=std::vector<int> (n);
        iota(begin(sz), end(sz), 1);
    }
    int get(int x){
        return e[x]<0? x : e[x]=get(e[x]);
    }
    bool same_set(int a, int b){
        return get(a)==get(b);
    }
    int size(int x){
        return -e[get(x)];
    }

    bool unite(int a, int b){
        a=get(a);
        b=get(b);
        if(a==b){
            return false;
        }
        if(size(a)>size(b)){
            swap(a, b);
        }
        e[a]+=e[b];
        e[b]=a;
        sz[a]+=sz[b];
        return true;
    }

    int get_size(int x){
        return sz[get(x)];
    }
};

class Postcards{
public:
    int count(int N, int Y, int seed){
        std::vector<int> a(Y);
        std::vector<int> b(Y);
        int state=seed;
        for(int i=0; i<Y; i++){
           state=(state * 1103515245 + 12345) % MOD;
           a[i]=state%N;
           state=(state * 1103515245 + 12345) % MOD;
           b[i]=state%N;     
        }
        DSU dsu=DSU(N);
        int ans=(N*(N-1))/2;
        ans%=mod;
        ans+=(((((N*(N-1))%mod)*(2*N-1))%mod)*166666668)%mod;
        ans%=mod;
        int total=0;
        for(int i=0; i<Y; i++){
            if(!dsu.same_set(a[i], b[i])){
               int subtract=dsu.get_size(a[i]);
               int add=dsu.get_size(b[i]);
               ans-=(subtract*(subtract-1))%mod;
               ans%=mod;
               while(ans<0)ans+=mod;
               ans-=(add*(add-1))%mod;
               ans%=mod;
               while(ans<0)ans+=mod;
               ans+=((add+subtract)*(add+subtract-1))%mod;
               ans%=mod;
               while(ans<0)ans+=mod;
               dsu.unite(a[i], b[i]);
            }
            total+=ans;
            total%=mod;
        } 
        return total;
    }
};

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    Postcards a;
    cout<<a.count(7, 1, 47);
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */