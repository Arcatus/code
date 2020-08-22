#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    if ( islower(s[0]) ) {
        for(int i = 1; i < s.size(); ++i) {
            if(islower(s[i])) {
                cout << s << '\n';
                return 0;
            }
        }
        cout << char(toupper(s[0]));
        for(int i = 1; i < s.size(); ++i) {
            cout << char(tolower(s[i]));
        }
        cout << '\n';
    } else {
        for(int i = 1;  i < s.size(); ++i) {
            if(islower(s[i])) {
                cout << s << '\n';
                return 0;
            }
        }
        for(int i = 0; i < s.size(); ++i) {
            cout << char(tolower(s[i]));
        }
        cout << '\n';
    }
    return 0;
}