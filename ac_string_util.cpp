#include <bits/stdc++.h>

using namespace std;

// 小文字、大文字変換用
char to_uppercase_char(char c) { return (char) toupper(c); }

char to_lowercase_char(char C) { return (char) tolower(C); }

string to_uppercase_str(const string &s) {
    string answer;
    for (const char &c : s) answer += to_uppercase_char(c);
    return answer;
}

string to_lowercase_str(const string &s) {
    string answer;
    for (const char &c : s) answer += to_lowercase_char(c);
    return answer;
}

void to_uppercase(string &s) { for (char &i : s) i = to_uppercase_char(i); }

void to_lowercase(string &s) { for (char &c : s) c = to_lowercase_char(c); }

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
vector<string> split_str(const string &s, char delim) {
    vector<string> tokens;
    string item;
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