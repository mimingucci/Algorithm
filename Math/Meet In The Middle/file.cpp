/*
author: mimingucci
created on: 11/26/2023 8:10:38 PM
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
    int n, x;
    cin>>n>>x;
    std::vector<int> t(n);
    for(int i=0; i<n; i++)cin>>t[i];
    auto get_all_subset_sums=[&](int l, int r)->std::vector<int>{
       std::vector<int> subsets;
       int sz=r-l+1;
       for(int i=0; i<(1<<sz); i++){
       	int sum=0;
       	for(int j=0; j<sz; j++){
       		if(i&(1<<j))sum+=t[l+j];
       	}
       	subsets.push_back(sum);
       }
       return subsets;
    };	
    int ans=0;
    std::vector<int> left=get_all_subset_sums(0, n/2-1);
    std::vector<int> right=get_all_subset_sums(n/2, n-1);
    sort(begin(left), end(left));
    sort(begin(right), end(right));
    for(int i : left){
    	auto low_iterator = lower_bound(right.begin(), right.end(), x - i);
		auto high_iterator = upper_bound(right.begin(), right.end(), x - i);
		int start_index = low_iterator - right.begin();
		int end_index = high_iterator - right.begin();
		ans += end_index - start_index;
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