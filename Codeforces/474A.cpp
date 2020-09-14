#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<char, char> L;
    map<char, char> R;
    string s = "qwertyuiop";
    for(int i = 0; i < s.size() - 1; ++i) {
        L.insert({s[i], s[i + 1]});
    }
    for(int i = 1; i < s.size(); ++i) {
        R.insert({s[i], s[i - 1]});
    }
    s = "zxcvbnm,./";
    for(int i = 0; i < s.size() - 1; ++i) {
        L.insert({s[i], s[i + 1]});
    }
    for(int i = 1; i < s.size(); ++i) {
        R.insert({s[i], s[i - 1]});
    }
    s = "asdfghjkl;";
    for(int i = 0; i < s.size() - 1; ++i) {
        L.insert({s[i], s[i + 1]});
    }
    for(int i = 1; i < s.size(); ++i) {
        R.insert({s[i], s[i - 1]});
    }
    char opc;
    cin >> opc;
    cin >> s;
    if(opc == 'R') {
        for(int i = 0; i < s.size(); ++i) {
            cout << R[s[i]];
        }
    } else {
        for(int i = 0; i < s.size(); ++i) {
            cout << L[s[i]];
        }
    }
    cout << '\n';
    return 0;
}