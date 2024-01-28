/*
author: mimingucci
created on: 1/11/2024 12:20:25 AM
*/
#include <bits/stdc++.h>
using namespace std;
const int64_t INF=(int64_t)1<<62;
const int MAXN= 1e6;

//link: https://community.topcoder.com/stat?c=problem_statement&pm=17801

int maxSubarraySum(vector<int> arr, int N, int K)
{
    multiset<int> cum_set;
    cum_set.insert(0);
 
    int max_sum = 0, cSum = 0;
 
    for (int i = 0; i < N; i++) {
 
        cSum += arr[i];
 
        auto sit
            = cum_set.upper_bound(cSum - K);
 
        if (sit != cum_set.end())
            max_sum = max(max_sum, cSum - *sit);
        cum_set.insert(cSum);
    }
 
    return max_sum;
}

class FeedADrake
{
public:
    int64_t feed(int stomach, vector <int> cakes, int excess){
        sort(begin(cakes), end(cakes));
        int64_t ans=0;
        while(excess>=0 && cakes.size()>0){
            ans+=cakes.back();
            cakes.pop_back();
            excess--;
        }
        int anss=maxSubarraySum(cakes, cakes.size(), stomach);
        return ans+anss;
    }
    
};

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */