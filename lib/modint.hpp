#pragma once
#include <cstdint>
#include <iosfwd>
#include <vector>

// modint.hpp
// Modular integer arithmetic for prime moduli.
// Template parameter "MOD" must be a positive integer (e.g., 998244353).

template<std::int32_t MOD>
requires (MOD > 0)
struct Mint {
    static_assert(MOD > 0, "Modulus must be positive");
    static constexpr int mod = MOD;

    int v;  // value in [0..mod)

    // ---- constructors -----------------------------------------------------
    constexpr Mint() noexcept : v(0) {}
    constexpr Mint(std::int64_t x) noexcept
        : v(static_cast<int>(((x % MOD) + MOD) % MOD)) {}

    // ---- conversion -------------------------------------------------------
    [[nodiscard]] constexpr int value() const noexcept { return v; }
    constexpr explicit operator int() const noexcept { return v; }

    // ---- in-place arithmetic ----------------------------------------------
    constexpr Mint& operator+=(const Mint& rhs) noexcept {
        v += rhs.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    constexpr Mint& operator-=(const Mint& rhs) noexcept {
        v -= rhs.v;
        if (v < 0) v += MOD;
        return *this;
    }
    constexpr Mint& operator*=(const Mint& rhs) noexcept {
        v = static_cast<int>((static_cast<std::int64_t>(v) * rhs.v) % MOD);
        return *this;
    }
    constexpr Mint& operator/=(const Mint& rhs) noexcept {
        return *this *= rhs.inv();
    }

    // ---- binary operators ----------------------------------------------
    friend constexpr Mint operator+(Mint lhs, const Mint& rhs) noexcept { return lhs += rhs; }
    friend constexpr Mint operator-(Mint lhs, const Mint& rhs) noexcept { return lhs -= rhs; }
    friend constexpr Mint operator*(Mint lhs, const Mint& rhs) noexcept { return lhs *= rhs; }
    friend constexpr Mint operator/(Mint lhs, const Mint& rhs) noexcept { return lhs /= rhs; }

    // ---- comparisons ------------------------------------------------------
    friend constexpr bool operator==(const Mint& a, const Mint& b) noexcept { return a.v == b.v; }
    friend constexpr bool operator!=(const Mint& a, const Mint& b) noexcept { return a.v != b.v; }

    // ---- power / inverse (Fermat's little theorem, mod must be prime) -----
    [[nodiscard]] constexpr Mint pow(std::int64_t e) const noexcept {
        Mint base = *this;
        Mint result = 1;
        while (e > 0) {
            if (e & 1) result *= base;
            base *= base;
            e >>= 1;
        }
        return result;
    }
    [[nodiscard]] constexpr Mint inv() const noexcept {
        return pow(MOD - 2);
    }
};

// ---- factorial / nCr helper ---------------------------------------------
template<class M>
struct Comb {
    std::vector<M> fact;
    std::vector<M> ifact;

    explicit Comb(int n = 0) { init(n); }

    void init(int n) {
        fact.assign(n+1, M(1));
        ifact.assign(n+1, M(1));
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1] * M(i);
        ifact[n] = M(1) / fact[n];
        for (int i = n; i > 0; --i) ifact[i-1] = ifact[i] * M(i);
    }

    [[nodiscard]] M nCr(int n, int r) const {
        if (r < 0 || r > n) return M(0);
        return fact[n] * ifact[r] * ifact[n-r];
    }
};
