#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int i;
    for(i = 0; i < s.size() - 1;) {
        if (s[i] == '.' && s[i + 1] == '.') {
            cout << 0; i++;
        } else if (s[i] == '.' && s[i + 1] == '-') {
            cout << 0; i++;
        } else if (s[i] == '-' && s[i + 1] == '.') {
            cout << 1; i+=2;
        } else if (s[i] == '-' && s[i + 1] == '-') { 
            cout << 2; i+=2;
        }
    }
    if (i < s.size()) {
        cout << 0; i++;
    }
    cout << '\n';
    return 0;
}