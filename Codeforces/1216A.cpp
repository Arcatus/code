#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i+=2) {
        if (s[i] == s[i + 1]) {
            ans++;
            s[i + 1] = (s[i] == 'a' ? 'b':'a');
        }
    }
    cout << ans << '\n';
    cout << s << '\n';
    return 0;
}