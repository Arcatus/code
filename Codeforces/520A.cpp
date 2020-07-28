#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    bool p[30] = { };
    for(int i = 0; i < n; ++i) {
        p[ tolower(s[i]) - 'a'] = true;
    }
    int cnt = 0;
    for(int i = 0; i < 26; ++i) {
        if(p[i]) cnt++;
    }
    if (cnt == 26) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}