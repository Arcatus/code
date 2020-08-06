#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a[4];
    for(int i = 0; i < 4; ++i) cin >> a[i];
    sort(a, a + 4);
    int ans = 0;
    for(int i = 1; i < 4; ++i) {
        if (a[i] == a[i - 1]) ans++;
    }
    cout << ans << '\n';
    return 0;
}