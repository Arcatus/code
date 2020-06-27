#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    for(int i=0; i<s.size(); ++i) {
        if( s[i] != t[i] ) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << '\n';
    return 0;
}