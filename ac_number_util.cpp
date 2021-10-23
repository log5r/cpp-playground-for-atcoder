//
// Created by Judau on 2021/10/17.
//

// 数値判定（ちょっとどうなんだろうこれ...）
bool is_number(char c) {
    return 48 <= c && c <= 57;
}

// char to int （ベータ版、というかもっといい方法ない？）
int c_to_int(char c) {
    if (is_number(c)) return c - 48;
    else return 0; // エラーにしたほうが良くない？
}

// char <-> int 相互変換
template <typename T>
char char_from(T num) { return char('0' + num); }

int int_from(char chr) { return int(chr - '0'); }

// 数値を桁ごとにばらして配列にする。小数点は -2 になる。
template <typename T>
vector<T> array_from(T num) {
    string s = to_string(num);
    vector<T> res;
    for (const char &c: s) res.template push_back(c - '0');
    return res;
}

// 各桁の数値を足す
template <typename T>
T sum_each_digit(T n) {
    T m;
    T sum = 0;
    while (n > 0) {
        m = n % 10;
        sum = sum + m;
        n /= 10;
    }
    return sum;
}

// 各桁の数値を一桁になるまで足す
template <typename T>
T rec_sum_each_digit(T n) {
    while (n > 9) n = sum_each_digit(n);
    return n;
}