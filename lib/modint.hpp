#pragma once
#include <cstdint>
#include <iosfwd>
#include <vector>
#include <type_traits>

// modint.hpp
// Modular integer arithmetic for prime moduli with configurable base type.
// Template parameters:
//   T    : integral type to store values (e.g., int32_t, int64_t)
//   MOD  : modulus value of type T, must satisfy 0 < MOD

template<typename T, T MOD>
requires(std::is_integral_v<T> && MOD > 0)
struct Mint {
    static_assert(std::is_integral_v<T>, "T must be an integral type");
    static_assert(MOD > 0, "Modulus must be positive");

    using value_type = T;
    static constexpr T mod = MOD;

    T v;  // value in [0..mod)

    // ---- constructors -----------------------------------------------------
    constexpr Mint() noexcept : v(0) {}
    constexpr Mint(T x) noexcept : v(((x % mod) + mod) % mod) {}
    constexpr Mint(std::int64_t x) noexcept : v(static_cast<T>(((x % mod) + mod) % mod)) {}

    // ---- conversion -------------------------------------------------------
    [[nodiscard]] constexpr T value() const noexcept { return v; }
    constexpr explicit operator T() const noexcept { return v; }

    // ---- in-place arithmetic ----------------------------------------------
    constexpr Mint& operator+=(const Mint& rhs) noexcept {
        v += rhs.v;
        if (v >= mod) v -= mod;
        return *this;
    }
    constexpr Mint& operator-=(const Mint& rhs) noexcept {
        v -= rhs.v;
        if (v < 0) v += mod;
        return *this;
    }
    constexpr Mint& operator*=(const Mint& rhs) noexcept {
        v = static_cast<T>((static_cast<std::int64_t>(v) * rhs.v) % mod);
        return *this;
    }
    constexpr Mint& operator/=(const Mint& rhs) noexcept {
        return *this *= rhs.inv();
    }

    // ---- binary operators ----------------------------------------------
    friend constexpr Mint operator+(Mint a, const Mint& b) noexcept { return a += b; }
    friend constexpr Mint operator-(Mint a, const Mint& b) noexcept { return a -= b; }
    friend constexpr Mint operator*(Mint a, const Mint& b) noexcept { return a *= b; }
    friend constexpr Mint operator/(Mint a, const Mint& b) noexcept { return a /= b; }

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
        return pow(mod - 2);
    }
};

// ---- factorial / nCr helper ---------------------------------------------
// Works with any Mint<T, MOD> type

template<typename M>
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
