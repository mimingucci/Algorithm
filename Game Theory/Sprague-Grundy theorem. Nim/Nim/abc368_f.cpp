/*
 * author:  mimingucci
 * created: [Sat] Aug 31, 2024 11:29:40
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e5;
const int MOD = 998244353; // 1e9+7

// link problem: https://atcoder.jp/contests/abc368/tasks/abc368_f

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    std::vector<int> a(n);
    for (int &i : a)
        cin >> i;
    std::vector<bool> prime(MAXN + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= MAXN; i++) {
        if (prime[i]) {
            for (int j = i; j * i <= MAXN; j++) {
                prime[j * i] = false;
            }
        }
    }
    std::vector<int> primes;
    for (int i = 2; i <= MAXN; i++)
        if (prime[i])
            primes.push_back(i);
    std::vector<int> cnt(MAXN + 1, int(-1));
    int grundy = 0;
    for (int i : a) {
        if (cnt[i] != -1) {
            grundy ^= cnt[i];
            continue;
        }
        int now = i;
        int count = 0;
        for (int j : primes) {
            if (now == 1)
                break;
            while (now % j == 0) {
                now /= j;
                ++count;
            }
        }
        cnt[i] = count;
        grundy ^= cnt[i];
    }
    if (grundy) {
        cout << "Anna";
    } else {
        cout << "Bruno";
    }
    return 0;
}