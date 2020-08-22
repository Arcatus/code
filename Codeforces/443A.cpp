#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    getline(cin, s);
    int n = s.size();
    int letters[26] = { };
    for(int i = 1; i < n; i+=3) {
        if( isalpha(s[i])) letters[s[i]-'a'] = 1;
    }
    int ans = 0;
    for(int i = 0; i < 26; ++i) {
        ans += letters[i];
    }
    cout << ans << '\n';
    return 0;
}