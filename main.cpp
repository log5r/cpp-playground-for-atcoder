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


ll gcd(ll a, ll b) {
    ll r = a % b;
    return r ? gcd(b, r) : b;
}

ll gcd_all(vector<ll> va) {
    ll ans = va.at(0);
    for (ll a : va) ans = gcd(ans, a);
    return ans;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

ll lcm_all(const vector<ll> &va) {
    ll ans = 1;
    for (ll a: va) ans = lcm(ans, a);
    return ans;
}

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

// solve ax + by = gcd(a, b)
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

bool solve_id_eq(ll a, ll b, ll &x, ll &y, ll c) {
    ll res = gcd_ext(a, b, x, y);
    if (c % res) {
        x = 0; y = 0;
        return false;
    }
    ll s = c / res;
    x = s * x;
    y = s * y;
    return true;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y;
    ll res = solve_id_eq(111, 30, x, y, 11);
    cout << x << ", " << y << "(res: " << res << ")"  << endl;
}
