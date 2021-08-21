#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ull = uint64_t;
using p_ll = pair<ll, ll>;
using m22_ll = pair<p_ll, p_ll>;

// ループ
#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rrep(i, n) for(int i=(n)-1; i>=0; --i)
#define xrep(i, begin, end) for(int i=(begin), i##_len=(end); i<=i##_len; ++i)
#define yrep(i, begin, end) for(int i=(begin), i##_len=(end); i>=i##_len; --i)
#define repr(vec) for (const auto&it: vec) // TODO: もっといい名前をつける
#define until(cond) while(!cond)

// 三項演算子の略記...?
#define cp3(p,q,l,r,m) ((p)==(q)?(m):(p)<(q)?(l):(r))

// 配列関連
#define all(x) (x).begin(),(x).end()
#define sort_reverse(x) sort((x).begin(),(x).end());reverse(all(x))
#define sort_unique(x) sort((x).begin(),(x).end());(x).erase(unique((x).begin(), (x).end()), (x).end())
#define merge_vec(v, a) v.insert((v).end(), (a).begin(),(a).end())

// 行列計算用
#define make_m22(a, b, c, d) make_pair(make_pair(a,b), make_pair(c,d))

// 必要かどうか微妙
#define UPDATE_NUM(current, challenger) if (challenger > current) current = challenger


/*  ここから下は関数  */

// vector の値を足すだけ
long long sum_vec_ll(const vector<long long>& vec) {
    long long ans = 0;
    for (long long v: vec) ans += v;
    return ans;
}

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

// 組み合わせ数を出力_2 （速いかもしれない）
ll comb_count_2(ll n, ll r) {
    if (r > n) return 0;
    if (r * 2 > n) r = n - r;
    if (r == 0) return 1;

    ll result = n;
    for (ll i = 2; i <= r; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

// combination リスト出力用に使えるかもしれない
vector<vector<long long>> comb(long long N, long long K) {
    string bitmask(K, 1);
    bitmask.resize(N, 0);
    vector<vector<long long>> res = {};
    do {
        vector<long long> unit = {};
        for (long long i = 0; i < N; ++i) {
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

// 約数の個数列挙
template <typename T>
T count_factors_of(T n) {
    T ans = 0;
    for (T i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans++;
            if (n / i != i) ans++;
        }
    }
    return ans;
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

// 素因数分解（普通の）
vector<ll> pfd(ll x) {
    vector<ll> res;
    for (ll i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            x /= i;
            res.push_back(i);
        }
    }
    if (x != 1) res.push_back(x);
    return res;
}

// 素因数分解（素因数とその数がペアになる版）
vector<pair<ll, ll>> pfd_vp(ll N) {
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

// 冪乗計算
ll mod_pow(ll base, ll exp, ll modulus) {
    base %= modulus;
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

// フィボナッチ数（積み上げ）
ull fibonacci(ull n) {
    ull p = 0;
    ull q = 1;
    if (n == 0) return p;
    if (n == 1) return q;
    for (int i = 0; i < n - 1; i++){
        ll buf = q;
        q = p + q;
        p = buf;
    }
    return q;
}

// リュカ数（積み上げ）
ull lucas(unsigned int n) {
    ull p = 2;
    ull q = 1;
    if (n == 0) return p;
    if (n == 1) return q;
    for (int i = 0; i < n - 1; i++){
        ll buf = q;
        q = p + q;
        p = buf;
    }
    return q;
}

// 平方行列の掛け算
m22_ll prod_m22(m22_ll x, m22_ll y) {
    return make_m22(
            x.first.first * y.first.first + x.first.second * y.second.first,
            x.first.first * y.first.second + x.first.second * y.second.second,
            x.second.first * y.first.first + x.second.second * y.second.first,
            x.second.first * y.first.second + x.second.second * y.second.second
    );
}

// 平方行列のべき乗
m22_ll pow_m22(m22_ll matrix, ull ext) {
    if (ext == 0) return make_m22(1, 0, 0, 1);
    else if (ext == 1) return matrix;
    else if (ext % 2 == 0) {
        m22_ll buf = prod_m22(matrix, matrix);
        return pow_m22(buf, ext / 2);
    } else {
        m22_ll buf1 = prod_m22(matrix, matrix);
        return prod_m22(matrix, pow_m22(buf1, ext / 2));
    }
}

// 平方行列を文字列にする
string m22_ll_to_string(m22_ll matrix) {
    return "[[" + to_string(matrix.first.first) + ", " + to_string(matrix.first.second) + "]"
           + "[" + to_string(matrix.second.first) + ", " + to_string(matrix.second.second) + "]]";
}

// フィボナッチ数（行列計算）
ull fibonacci_m22(ull n) {
    return pow_m22(make_m22(0, 1, 1, 1), n).first.second;
}


// 各数字が何個入っているか数えるとき用
vector<vector<long long>> group_count_map(vector<long long> vec) {
    SORT(vec);
    vec.push_back(2e9);
    int latest = vec.front();
    int rCount = 0;
    vector<vector<long long>> resMap;
    for (int i : vec) {
        if (i != latest) {
            vector<long long> b(2);
            b.at(0) = latest;
            b.at(1) = rCount;
            resMap.push_back(b);

            latest = i;
            rCount = 1;
        } else {
            rCount++;
        }
    }
    return resMap;
}

// 回文判定
bool is_palindrome(const string& s) {
    string rs = s;
    reverse(rs.begin(), rs.end());
    return s == rs;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y;
    ll res = solve_id_eq(111, 30, x, y, 11);
    cout << x << ", " << y << "(res: " << res << ")" << endl;
}

// Union find 木が必要なとき
struct union_find {
    vector<long long> r;

    explicit union_find(long long N) {
        r = vector<long long>(N, -1);
    }

    long long root(long long x) {
        if (r.at(x) < 0) return x;
        return r.at(x) = root(r.at(x));
    }

    bool unite(long long x, long long y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r.at(x) > r.at(y)) swap(x, y);
        r.at(x) += r.at(y);
        r.at(y) = x;
        return true;
    }

    long long size(long long x) {
        return -r.at(root(x));
    }
};
