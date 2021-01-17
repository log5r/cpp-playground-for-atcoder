#include <bits/stdc++.h>

// デバッグ出力用
#define pln(text) cout << text << endl
#define dbg(label, text) cout << label << ": " << text << endl
#define pstr(text) cout << text
#define endpstr << endl;

/* ここからデバッグ用定義 */
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
