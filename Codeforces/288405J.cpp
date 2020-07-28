#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n > 26) {
        cout << -1 << '\n';
    } else {
        int cnt[26] = { };
        for(int i = 0; i < n; ++i) {
            cnt[s[i] - 'a']++;
        }
        int ans = 0;
        for(int i = 0; i < 26; ++i) {
            ans += (cnt[i] > 0 ? cnt[i] - 1 : 0);
        }
        cout << ans << '\n';
    }
    return 0;
}