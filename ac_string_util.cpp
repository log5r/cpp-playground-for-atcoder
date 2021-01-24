#include <bits/stdc++.h>

// 小文字、大文字変換用
char to_uppercase_char(char c) { return (char) toupper(c); }

char to_lowercase_char(char C) { return (char) tolower(C); }

std::string to_uppercase_str(const std::string &s) {
    std::string answer;
    for (const char &c : s) answer += to_uppercase_char(c);
    return answer;
}

std::string to_lowercase_str(const std::string &s) {
    std::string answer;
    for (const char &c : s) answer += to_lowercase_char(c);
    return answer;
}

void to_uppercase(std::string &s) { for (char &i : s) i = to_uppercase_char(i); }

void to_lowercase(std::string &s) { for (char &c : s) c = to_lowercase_char(c); }

// 数値判定（ちょっとどうなんだろうこれ...）
bool is_number(char c) {
    return 48 <= c && c <= 57;
}

// char to int （ベータ版、というかもっといい方法ない？）
int c_to_int(char c) {
    if (is_number(c)) return c - 48;
    else return 0; // エラーにしたほうが良くない？
}

// 分割
std::vector<std::string> split_str(const std::string &s, char delim) {
    std::vector<std::string> tokens;
    std::string item;
    for (char c: s) {
        if (c == delim) {
            if (!item.empty()) tokens.push_back(item);
            item.clear();
        } else {
            item += c;
        }
    }
    if (!item.empty()) tokens.push_back(item);
    return tokens;
}

// 書式文字列 on C++11
template<typename ... args_t>
std::string format(const std::string &fmt, args_t ... args) {
    size_t len = std::snprintf(nullptr, 0, fmt.c_str(), args ...);
    std::vector<char> buf(len + 1);
    std::snprintf(&buf[0], len + 1, fmt.c_str(), args ...);
    return std::string(&buf[0], &buf[0] + len);
}
