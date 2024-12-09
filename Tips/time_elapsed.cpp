/*
 * author:  mimingucci
 * created:
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

class mimingucci {
  public:
    mimingucci() : start_time(std::clock()) {}

    ~mimingucci() {
#ifdef LOCAL
        std::cerr << "Time elapsed: "
                  << 1.0 * (std::clock() - start_time) / CLOCKS_PER_SEC
                  << " milliseconds.";
#endif
    }

  private:
    std::clock_t start_time;
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    mimingucci yah;
    int t;
    cin >> t;
    while (t--) {
        // g++ -DLOCAL -std=c++2b file.cpp -o file && file.exe
    }
    return 0;
}