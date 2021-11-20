#include <bits/stdc++.h>
using namespace std;

// ...本当に使うんですかね

#define bitbfs(tmp, bit_size) for (int tmp = 0; tmp < (1 << bit_size); tmp++)

/// bitset を使わずに、考えられるビット列を全列挙
/// \param size ビット列の長さ
/// \return あり得るビット列のセット
vector<string> bitt_str_list(int size) {
    vector<string> res;
    for (int i = 0; i < (1 << size); ++i) {
        string buf;
        for (int j = size - 1; j >= 0; --j) {
            buf += (i & (1 << j)) ? '1' : '0';
        }
        res.push_back(buf);
    }
    return res;
}
