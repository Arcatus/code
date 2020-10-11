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
    string ans = "";
    ans += s[0];
    for(int i = 1; i < n; ++i) {
        if(i % 2 == 0) {
            ans = s[i] + ans;
        } else {
            ans = ans + s[i];
        }
    }
    if(n & 1) reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}