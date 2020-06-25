#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int upp=0, loww=0;
    for(int i=0; i<n; ++i) {
        if( isupper(s[i]) ) {
            upp++;
        } else loww++;
    }
    if(upp <= loww) {
        for(int i=0; i<n; ++i) {
            cout << char(tolower(s[i]));
        }
        cout << '\n';
    } else {
        for(int i=0; i<n; ++i) {
            cout << char(toupper(s[i]));
        }
        cout << '\n';
    }
    return 0;
}