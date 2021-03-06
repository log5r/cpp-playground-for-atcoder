#include <bits/stdc++.h>

#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rrep(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

struct matrix {
    vector<vector<int>> m;
    vector<ll> c;

    explicit matrix(const vector<vector<int>> &_m = {{1, 0},
                                                     {0, 1}},
                    const vector<ll> &_c = {0, 0}) : m(_m), c(_c) {}

    matrix operator*(const matrix &x) const {
        matrix res({{0, 0}, {0, 0 }});
        rep(i, 2) rep(j, 2) rep(k, 2) res.m.at(i).at(j) += x.m.at(i).at(k) * m.at(k).at(j);
        res.c = matrix(x.m) * c;
        rep(i, 2) {
            res.c.at(i) += x.c.at(i);
        }
        return res;
    }

    vector<ll> operator*(const vector<ll> &x) const {
        vector<ll> res = c;
        rep(i, 2) rep(j, 2) res.at(i) += m.at(i).at(j) * x.at(j);
        return res;
    }
};
