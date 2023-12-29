/*
author: mimingucci
created on: 12/29/2023 1:51:18 PM
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
const int INF=(int)1<<62;
const int MAXN=1e6;
const int MOD=1e9+7;

int fac[MAXN + 1];
int inv[MAXN + 1];

/** Computes x^n modulo m in O(log p) time. */
int exp(int x, int n, int m) {
   x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
   int res = 1;
   while (n > 0) {
      if (n % 2 == 1) { res = res * x % m; }
      x = x * x % m;
      n /= 2;
   }
   return res;
}

/** Precomputes n! from 0 to MAXN. */
void factorial(int p) {
   fac[0] = 1;
   for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % p; }
}

/**
 * Precomputes all modular inverse factorials
 * from 0 to MAXN in O(n + log p) time
 */
void inverses(int p) {
   inv[MAXN] = exp(fac[MAXN], p - 2, p);
   for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % p; }
}

/** Computes nCr mod p */
int choose(int n, int r, int p) {
   //nCr
   return fac[n] * inv[r] % p * inv[n - r] % p;
   //nPr
   // return fac[n] % p * inv[n - r] % p;
}

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    factorial(MOD);
    inverses(MOD);
    cout<<choose(5, 3, MOD);
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */