/*
author: mimingucci
created on: 3/16/2024 10:56:38 AM
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

int bit[2000005];

void update(int i, int x) {
	for (; i < 2000005; i += i & (-i)) bit[i] += x;
}
int query(int i) {
	int sum = 0;
	for (; i > 0; i -= i & (-i)) sum += bit[i];
	return sum;
}

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    std::vector<array<int, 4>> v;
    for(int i=0; i<n; i++){
    	int x1, x2, y1, y2;
    	cin>>x1>>y1>>x2>>y2;
    	if(y1==y2){
    		v.push_back({y1, 2, x1, x2});
    	}else{
    		v.push_back({y1, 1, x1, 0});
    		v.push_back({y2, 3, x1, 0});    		
    	}
    }
    sort(begin(v), end(v));
    int ans=0;
    for(auto x : v){
    	x[2]+=1000001;
    	x[3]+=1000001;
    	if(x[1]==1){
    		update(x[2], 1);
    	}else{
    		if(x[1]==2){
    			ans+=query(x[3])-query(x[2]-1);
    		}else{
    			update(x[2], -1);
    		}
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