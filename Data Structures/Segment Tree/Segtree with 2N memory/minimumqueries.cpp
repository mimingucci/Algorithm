/*
author: mimingucci
created on: 9/16/2023 8:17:54 PM
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF=(int)1<<62;
const int MAXN= 1e6;

template<class T> class MinSegtree{
   private:
    const T DEFAULT=INF;
    int len;
    std::vector<T> segtree;
   public:
    MinSegtree(int n){
    	len=n;
    	segtree.assign(2*len, DEFAULT);
    } 	

    void set(int index, T val){
    	index+=len;
    	segtree[index]=val;
    	for( ; index>1; index/=2){
    		segtree[index/2]=min(segtree[index], segtree[index^1]);
    	}
    }

    T minimum_queries(int start, int end){
    	T minimum=DEFAULT;
    	for(start+=len, end+=len; start<end; start/=2, end/=2){
    		if(start%2==1){
    			minimum=min(minimum, segtree[start++]);
    		}
    		if(end%2==1){
    			minimum=min(minimum, segtree[--end]);
    		}
    	}
    	return minimum;
    }
};

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int arr_len;
	int query_num;
	std::cin >> arr_len >> query_num;

	MinSegtree<int> segtree(arr_len);
	for (int i = 0; i < arr_len; i++) {
		int n;
		std::cin >> n;
		segtree.set(i, n);
	}

	for (int q = 0; q < query_num; q++) {
		int type, arg1, arg2;
		std::cin >> type >> arg1 >> arg2;
		if (type == 1) {
			segtree.set(arg1 - 1, arg2);
		} else if (type == 2) {
			cout << segtree.minimum_queries(arg1 - 1, arg2) << '\n';
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