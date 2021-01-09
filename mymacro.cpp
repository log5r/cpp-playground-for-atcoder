#include <bits/stdc++.h>
using namespace std;

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


// 順列数を出力

int64_t perm_count(int64_t n, int64_t k) {
    int64_t answer = n;
    for (int i = 2; i <= k; ++i) {
        answer *= (n - i + 1);
    }
    return answer;
}

// 組み合わせ数を出力
void comb(vector<vector<int64_t> > &v) {
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
int64_t comb_count(int64_t n, int64_t r) {
    vector<vector<int64_t>> v(n + 1, vector<int64_t>(n + 1, 0));
    comb(v);
    return v[n][r];
}

// combination リスト出力用に使えるかもしれなし
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
