/*
author: mimingucci
created on: 12/11/2023 1:31:08 PM
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
    std::vector<pair<int, int>> person;
    std::map<int, int> st;
    std::map<int, int> en;
    set<int> s;
    for(int i=0; i<n; i++){
    	int arr_time, leave_time;
    	cin>>arr_time>>leave_time;
    	st[arr_time]++;
    	en[leave_time]++;
    	s.insert(arr_time);
    	s.insert(leave_time);
    }
    int ans=0;
    int counter=0;
    for(int i : s){
    	counter+=st[i];
    	counter-=en[i];
    	ans=max(ans, counter);
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