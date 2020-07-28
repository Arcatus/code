#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b, c;
    cin >> a >> b >> c;
    int cnt[26] = { };
    for(int i = 0; i < a.size(); ++i) {
        cnt[a[i]-'A']++;
    }
    for(int i = 0; i < b.size(); ++i) {
        cnt[b[i]-'A']++;
    }
    int cnt2[26] = { };
    for(int i = 0; i < c.size(); ++i) {
        cnt2[c[i]-'A']++;
    }
    for(int i = 0; i < 26; ++i) {
        if (cnt2[i] != cnt[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}