#include <bits/stdc++.h>
using namespace std;
#define N1 101
#define N2 101
#define K1 11
#define K2 11
#define MOD 100000000

int n1, n2, k1, k2;
long long C[N1][N2][K1][K2];
int main() {
    memset(C, 0, sizeof C);
    cin >> n1 >> n2 >> k1 >> k2;

    for(int f = 0; f <= n1; f++) {
       for(int h = 0; h <= n2; h++) {
          for(int kf = 0; kf <= k1; kf++) {
             for(int kh = 0; kh <= k2; kh++) {
                long long ans;
                if(f + h == 0) ans = 1;
                else {
                    ans = 0;
                    if(f > 0 && kf > 0) ans = (ans + C[f - 1][h][kf - 1][k2]) % MOD;
                    if(h > 0 && kh > 0) ans = (ans + C[f][h - 1][k1][kh - 1]) % MOD;
                }
                C[f][h][kf][kh] = ans;
              }
           }
        }
    }
    cout << C[n1][n2][k1][k2] << endl;
    return 0;
}