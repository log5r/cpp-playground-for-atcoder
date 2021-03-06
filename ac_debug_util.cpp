#include <bits/stdc++.h>

// お手軽デバッグプリント
#define varp(var) cout << #var << " : " << var
// デバッグ出力用その他
#define pln(text) cout << text << endl
#define dbg(label, text) cout << label << ": " << text << endl
// 入力がめんどいからって作ったけど使うかなぁ...
#define ppp cout << text
#define eel << endl

/* ここからデバッグ用定義 */
// 注意: 記述する順番によっては下記のエラーになる
// > Call to function 'operator<<' that is neither visible in the template definition nor found by argument-dependent lookup

template<typename L, typename R>
std::ostream & operator<<(std::ostream & Str, pair<L, R> const & p) {
    Str << "< " << p.first << " : " << p.second << " >";
    return Str;
}

template<typename T>
std::ostream & operator<<(std::ostream & Str, vector<T> const & vec) {
    Str << "[";
    for (int i = 0; i < vec.size(); ++i) {
        if (i != 0) cout << ", ";
        cout << vec.at(i);
    }
    Str << "]";
    return Str;
}

// 使うかどうかは怪しいけどラベルが必要になったらこれ
template<typename T>
void dbgp_vector(const string& label, vector<T> vec) {
    cout << "DEBUG_VECTOR " << label << ": [";
    for (int i = 0; i < vec.size(); ++i) {
        if (i != 0) cout << ", ";
        cout << vec.at(i);
    }
    cout << "]" << endl;
}
