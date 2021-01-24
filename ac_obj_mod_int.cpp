#include <bits/stdc++.h>

// mod int
const long long MOD = 998244353;

struct mint {
    long long int x;

    mint() : x(0) {}

    explicit mint(long long int x) : x((x % MOD + MOD) % MOD) {}

    mint &fix() {
        x = (x % MOD + MOD) % MOD;
        return *this;
    }

    mint operator-() const { return mint(0) - *this; }

    mint operator~() const { return mint(1) / *this; }

    mint &operator+=(const mint &a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }

    mint &operator-=(const mint &a) {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }

    mint &operator*=(const mint &a) {
        (x *= a.x) %= MOD;
        return *this;
    }

    mint &operator/=(const mint &a) {
        (x *= a.pow(MOD - 2).x) %= MOD;
        return *this;
    }

    mint operator+(const mint &a) const { return mint(*this) += a; }

    mint operator-(const mint &a) const { return mint(*this) -= a; }

    mint operator*(const mint &a) const { return mint(*this) *= a; }

    mint operator/(const mint &a) const { return mint(*this) /= a; }

    mint pow(long long int t) const {
        if (!t) return mint(1);
        mint res = pow(t / 2);
        res *= res;
        return (t & 1) ? res * mint(x) : res;
    }

    bool operator<(const mint &a) const { return x < a.x; }

    bool operator==(const mint &a) const { return x == a.x; }
};

mint ex(mint x, long long int t) {
    return x.pow(t);
}

std::istream &operator>>(std::istream &i, mint &a) {
    i >> a.x;
    return i;
}

std::ostream &operator<<(std::ostream &o, const mint &a) {
    o << a.x;
    return o;
}
