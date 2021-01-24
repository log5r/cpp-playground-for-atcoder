#include <bits/stdc++.h>

// mod int
const long long MOD = 998244353;

struct mint {
    long long int value;

    mint() : value(0) {}

    explicit mint(long long int value) : value((value % MOD + MOD) % MOD) {}

    mint &fix() {
        value = (value % MOD + MOD) % MOD;
        return *this;
    }

    mint operator-() const { return mint(0) - *this; }

    mint operator~() const { return mint(1) / *this; }

    mint &operator+=(const mint &others) {
        if ((value += others.value) >= MOD) value -= MOD;
        return *this;
    }

    mint &operator-=(const mint &others) {
        if ((value += MOD - others.value) >= MOD) value -= MOD;
        return *this;
    }

    mint &operator*=(const mint &others) {
        (value *= others.value) %= MOD;
        return *this;
    }

    mint &operator/=(const mint &others) {
        (value *= others.pow(MOD - 2).value) %= MOD;
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
        return (t & 1) ? res * mint(value) : res;
    }

    bool operator<(const mint &a) const { return value < a.value; }

    bool operator<=(const mint &a) const { return value <= a.value; }

    bool operator>(const mint &a) const { return value > a.value; }

    bool operator>=(const mint &a) const { return value >= a.value; }

    bool operator==(const mint &a) const { return value == a.value; }
};

mint ex(mint x, long long int t) {
    return x.pow(t);
}

std::istream &operator>>(std::istream &i, mint &a) {
    i >> a.value;
    return i;
}

std::ostream &operator<<(std::ostream &o, const mint &a) {
    o << a.value;
    return o;
}

// 組み合わせ数を出力（mod int 版）
mint comb_count_mint(mint n, mint r) {
    if (r > n) return mint(0);
    if (r * mint(2) > n) r = n - r;
    if (r == mint(0)) return mint(1);

    mint result = n;
    for (long long int i = 2; mint(i) <= r; ++i) {
        result *= (n - mint(i) + mint(1));
        result /= mint(i);
    }
    return result;
}
