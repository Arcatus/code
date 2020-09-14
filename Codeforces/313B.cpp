#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    s = "$" + s;
    int n;
    cin >> n;
    int l, r;
    int pre[s.size()] = { };
    if(s[1] == s[2]) pre[1] = 1;
    for(int i = 2; i < s.size() - 1; ++i) {
        pre[i] = (s[i] == s[i + 1]) + pre[i - 1];
    }
    for(int i = 0; i < n; ++i) {
        cin >> l >> r;
        cout << pre[r - 1] - pre[l - 1] << '\n';
    }
    return 0;
}