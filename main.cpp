#include <bits/stdc++.h>
using namespace std;

//char get_winner(char a, char b) {
//    if(a == 'R' && b == 'S') return a;
//    if(a == 'P' && b == 'R') return a;
//    if(a == 'S' && b == 'P') return a;
//    return b;
//}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    auto get_winner = [&](char a, char b) -> char {
        if(a == 'R' && b == 'S') return a;
        if(a == 'P' && b == 'R') return a;
        if(a == 'S' && b == 'P') return a;
        return b;
    };
    for(int i = 0; i < k; ++i){
        s += s;
        string str;
        for(int j = 0; j < n; ++j){
            str += get_winner(s[2 * j], s[2 * j + 1]);
        }
        s = str;
        cout << s.front() << endl;
    }
}
