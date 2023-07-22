#include <bits/stdc++.h>
using namespace std;
const int K=25;
const int MAXN=10000000;
long long st[K + 1][MAXN];

main(){
	cin.tie(0)->sync_with_stdio(0);
	std::vector<int> a;
    //input a
    int N=a.size();
    std::copy(a.begin(), a.end(), st[0]);
    
    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= N; j++)
            st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];

    //query
    long long sum = 0;
    for (int i = K; i >= 0; i--) {
        if ((1 << i) <= R - L + 1) {
           sum += st[i][L];
           L += 1 << i;
        }
    }    
}

// Range Sum Queries