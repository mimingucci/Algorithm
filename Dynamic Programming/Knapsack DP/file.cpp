#include <bits/stdc++.h>
using namespace std;
#define ii int64_t
const ii mod=1000000007;
ii dp[1000001];
int main(){
	cin.tie(0)->sync_with_stdio(0);
    ii n;
    cin>>n;
    dp[0]=1;
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i - j >= 0) { 
				dp[i] += dp[i - j]; 
			}
		}
		dp[i] %= mod;
	}
	cout << dp[n] << "\n";
	return 0;
}