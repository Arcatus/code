#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    while(n--) {
        cin >> s;
        sort(s.begin(), s.end());
        bool ok = true;
        for(int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1] || s[i] - s[i - 1] != 1 ) {
                ok = false; break;
            }
        }
        cout << (ok ? "Yes":"No") << '\n';
    }
    return 0;
}