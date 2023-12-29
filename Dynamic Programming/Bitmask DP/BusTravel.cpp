/*
author: mimingucci
created on: 12/24/2023 7:39:35 PM
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
//link problem: https://community.topcoder.com/stat?c=problem_statement&pm=18146
class BusTravel{
    public:
    	int optimize(int N, int S, int M, int A){
    		std::vector<int> dp(1<<N, N*M);
    		dp[(1<<N)-1]=0;
    		int ans=M*N;
    		for(int i=(1<<N)-1; i>0; i--){
                int loc=__builtin_popcount(i);
                if(loc==S){
                	ans=min(ans, dp[i]);
                	continue;
                }
                if(loc<S){
                	continue;
                }
                for(int j=0; j<N; j++){
                	if((i>>j)&1){
                		for(int k=0; k<N; k++){
                			if(k!=j && (i>>k)&1){
                				dp[i-(1<<j)]=min(dp[i-(1<<j)], dp[i]+((N-loc+1)*(j+4)*(j+k+A)%M)+1);
                			}
                		}
                	}
                }
    		}
    		return ans;
    	}
};

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */