/*
 * author:  mimingucci
 * created: [Fri] Dec 06, 2024 22:11:51
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

class MinesweeperStrings {
  public:
    string generate(int N, long long X) {

        if (X >= 1LL << N)
            return "";
        X++;
        string S;

        int i;
        int pre = 0;
        for (i = 0; i < N; i++) {

            if (pre == 0) {
                if (X <= 1LL << (N - 1 - i)) {
                    S += "*";
                } else {
                    X -= 1LL << (N - 1 - i);
                    S += ".";
                    pre = 1;
                }
            } else {
                if (X <= 1LL << (N - 1 - i)) {
                    S += ".";
                } else {
                    X -= 1LL << (N - 1 - i);
                    S += "*";
                    pre = 0;
                }
            }
        }
        for (i = 0; i < N; i++)
            if (S[i] == '.') {
                int x = '0';
                if (i && S[i - 1] == '*')
                    x++;
                if (i + 1 < N && S[i + 1] == '*')
                    x++;
                S[i] = x;
            }

        return S;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    MinesweeperStrings sol;
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x;
        cin >> n >> x;
        cout << sol.generate(n, x) << '\n';
    }
    return 0;
}