/*
author: mimingucci
created on: 9/16/2023 8:04:25 PM
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF=(int)1<<62;
const int MAXN= 1e6;

template<class T> class SumSegtree{
  private:
  	const T DEFAULT = 0;
  	int len;
  	std::vector<T> segtree;
  public:
    SumSegtree(int n){
    	len=n;
    	segtree.assign(2*len, DEFAULT);
    }	

    void set(int index, T val){
    	index+=len;
    	segtree[index]=val;
    	for( ; index>1; index/=2){
           segtree[index/2]=segtree[index]+segtree[index^1];
    	}
    }

    //calculate sum in [start, end)
    T sum_queries(int start, int end){
       T sum=DEFAULT;
       for(start+=len, end+=len; start<end; start/=2, end/=2){
       	 if(start%2==1){
       	 	sum+=segtree[start++];
       	 }
       	 if(end%2==1){
       	 	sum+=segtree[--end];
       	 }
       }
       return sum;
    }
	
};

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int arr_len;
	int query_num;
	std::cin >> arr_len >> query_num;

	SumSegtree<int> segtree(arr_len);
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
			cout << segtree.sum_queries(arg1 - 1, arg2) << '\n';
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