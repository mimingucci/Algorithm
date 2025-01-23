/*
 * author:  mimingucci
 * created: [Thu] Jan 23, 2025 10:57:09
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    cin >> N;
    std::vector<int> A(N);
    for (int &i : A)
        cin >> i;
    // Decision function
    // Can we make K pairs?
    const auto check{[N, &A](unsigned K) {
        for (int i = 0; i < K; ++i)
            // Take the first K and the last K
            if (A[i] * 2 > A[N - K + i])
                // If any pair is invalid, return false
                return false;
        // Otherwise, return true
        return true;
    }};
    // Use binary search to find the maximum value between 0 and N/2 for which
    // the decision function is true (in other words, minimum value with false
    // minus one)
    cout << *ranges::partition_point(views::iota(0, N / 2 + 1), check) - 1
         << endl;
    return 0;
}