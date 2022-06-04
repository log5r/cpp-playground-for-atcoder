#include <bits/stdc++.h>
using namespace std;

/// 線形篩
/// \param n 上限
/// \return 得られた素数列、最小素因数列 のタプル
tuple<vector<long long>, vector<long long>> linear_sieve(long long n) {
    vector<long long> primes;
    vector<long long> lpf = vector<long long>(n + 1, -1);
    for (int d = 2; d <= n; ++d) {
        if (lpf[d] == -1) {
            lpf[d] = d;
            primes.push_back(d);
        }
        for (const auto &p: primes) {
            if (p * d > n || p > lpf[d]) break;
            lpf[p * d] = p;
        }
    }
    return make_tuple(primes, lpf);
}
