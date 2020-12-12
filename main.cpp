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

int main(){
    int N; cin >> N;
    vector<int> dl(N); rep(i, N) cin >> dl.at(i);
    SORT(dl);

    int latest_radius = 2e9;
    int height = 0;
    until(dl.empty()) {
        int current_radius = dl.back();
        if (latest_radius > current_radius) {
            height++;
            latest_radius = current_radius;
        }
        dl.pop_back();
    }
    pln(height);
}
