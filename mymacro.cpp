#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

#define pln(text) cout << text << endl
#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define repr(vec) for (const auto&it: vec)
#define all(x) (x).begin(),(x).end()
#define until(cond) while(!cond)
#define MERGE(v, a) v.insert(v.end(), all(a))
#define SORT(x) sort(all(x))
#define SORT_REVERSE(x) SORT(x);reverse(all(x))
#define SORT_UNIQUE(v) SORT(v);v.erase(unique(v.begin(), v.end()), v.end())
#define UPDATE_NUM(current, challenger) if (challenger > current) current = challenger

// 最大公約数
ll gcd(ll a, ll b) {
    ll r = a % b;
    return r ? gcd(b, r) : b;
}

// 3個以上の最大公約数
ll gcd_all(vector<ll> va) {
    ll ans = va.at(0);
    for (ll a : va) ans = gcd(ans, a);
    return ans;
}

// 最小公倍数
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

// 3個以上の最小公倍数
ll lcm_all(const vector<ll> &va) {
    ll ans = 1;
    for (ll a: va) ans = lcm(ans, a);
    return ans;
}

// 各桁の数値を足す
ll sum_each_digit(ll n) {
    ll m;
    ll sum = 0;
    while (n > 0) {
        m = n % 10;
        sum = sum + m;
        n = n / 10;
    }
    return sum;
}

// 一時不定方程式 ax + by = gcd(a, b) を解く
ll gcd_ext(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = gcd_ext(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// 一時不定方程式 ax + by = c を解く用(上もセット)
bool solve_id_eq(ll a, ll b, ll &x, ll &y, ll c) {
    ll res = gcd_ext(a, b, x, y);
    if (c % res) {
        x = 0;
        y = 0;
        return false;
    }
    ll s = c / res;
    x = s * x;
    y = s * y;
    return true;
}

// 順列数を出力
ll perm_count(ll n, ll k) {
    ll answer = n;
    for (int i = 2; i <= k; ++i) {
        answer *= (n - i + 1);
    }
    return answer;
}

// 組み合わせ数を出力
void comb(vector<vector<ll> > &v) {
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int k = 1; k < v.size(); k++) {
        for (int j = 1; j < k; j++) {
            v[k][j] = (v[k - 1][j - 1] + v[k - 1][j]);
        }
    }
}

ll comb_count(ll n, ll r) {
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
    comb(v);
    return v[n][r];
}

// combination リスト出力用に使えるかもしれない
vector<vector<int>> comb(int N, int K) {
    string bitmask(K, 1);
    bitmask.resize(N, 0);
    vector<vector<int>> res = {};
    do {
        vector<int> unit = {};
        for (int i = 0; i < N; ++i) {
            if (bitmask[i]) unit.push_back(i);
        }
        res.push_back(unit);
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
    return res;
}


//素数判定
bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

// 約数列挙
vector<ll> factors(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            if (n / i != i) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

// 素因数分解
vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<long long, long long> > res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.emplace_back(a, ex);
    }
    if (N != 1) res.emplace_back(N, 1);
    return res;
}

// python の modpow
template <typename T>
T mod_pow(T base, T exp, T modulus) {
    base %= modulus;
    T result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y;
    ll res = solve_id_eq(111, 30, x, y, 11);
    cout << x << ", " << y << "(res: " << res << ")" << endl;
}
