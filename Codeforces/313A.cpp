#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    if (s[0] == '-') {
        int n = s.size();
        if (s.size() <= 2) {
            cout << 0 << '\n';
        } else {
            if(s[n - 2] > s[n - 1]) {
                s.erase(n - 2, 1);
            } else {
                s.erase(n - 1, 1);
            }
            if(s[1] == '0' && s.size() == 2) {
                cout << 0 << '\n';
            } else {            
                cout << s << '\n';
            }
        }
    } else {
        cout << s << '\n';
    }
    return 0;
}