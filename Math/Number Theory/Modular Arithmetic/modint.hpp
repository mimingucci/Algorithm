#include <bits/stdc++.h>
using namespace std;

template <int MOD> requires (MOD > 0)
struct Mint {
    static constexpr int mod = MOD;   

    int v = 0;                         // always 0 ≤ v < mod

    // ---- constructors -----------------------------------------------------
    constexpr Mint(int x = 0) {
        v = int(((x % mod) + mod) % mod);
    }

    // ---- conversions ------------------------------------------------------
    constexpr explicit operator int() const        { return v; }

    // ---- in-place arithmetic ----------------------------------------------
    constexpr Mint& operator+=(const Mint& o) {
        v += o.v;
        if (v >= mod) v -= mod;
        return *this;
    }
    constexpr Mint& operator-=(const Mint& o) {
        v -= o.v;
        if (v < 0) v += mod;
        return *this;
    }
    constexpr Mint& operator*=(const Mint& o) {
        v = int(((__int128)v * o.v) % mod);   // promote to 128-bit, then reduce
        return *this;
    }
    constexpr Mint& operator/=(const Mint& o) { return *this *= o.inv(); }

    // ---- friend binary operators ------------------------------------------
    friend constexpr Mint operator+(Mint a, const Mint& b) { return a += b; }
    friend constexpr Mint operator-(Mint a, const Mint& b) { return a -= b; }
    friend constexpr Mint operator*(Mint a, const Mint& b) { return a *= b; }
    friend constexpr Mint operator/(Mint a, const Mint& b) { return a /= b; }
    friend constexpr bool operator==(const Mint& a, const Mint& b) { return a.v == b.v; }
    friend constexpr bool operator!=(const Mint& a, const Mint& b) { return a.v != b.v; }

    // ---- power / inverse (Fermat, mod should be prime) --------------------
    constexpr Mint pow(int e) const {
        Mint base = *this, res = 1;
        while (e) {
            if (e & 1) res *= base;
            base *= base;
            e >>= 1;
        }
        return res;
    }
    constexpr Mint inv() const { return pow(mod - 2); }
};

// Pre-computed factorial / nCr helper                                   
template <class M>
struct Comb {
    vector<M> fact{1}, ifact{1};
    Comb(int n = 0) { ensure(n); }

    void ensure(int n) {
        if ((int)fact.size() > n) return;
        int cur = fact.size();
        fact.resize(n + 1);
        ifact.resize(n + 1);
        for (int i = cur; i <= n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n] = M(1) / fact[n];
        for (int i = n; i > cur; --i) ifact[i - 1] = ifact[i] * i;
    }
    M nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        ensure(n);
        return fact[n] * ifact[r] * ifact[n - r];
    }
};

/* ------------------------------------------------------------------------- */
/* 3. Usage example                                                          */
/* ------------------------------------------------------------------------- */
/*
using mint = Mint<998244353>;

int main() {
    mint a = 123456789;
    mint b = 987654321;
    cout << (a * b + 42).pow(123456).v << '\n';
    Comb<mint> C(maxN);          // call once with upper bound
    mint ways = C.nCr(n, k);
}
*/
// ─────────────────────────────────────────────────────────────────────────────
