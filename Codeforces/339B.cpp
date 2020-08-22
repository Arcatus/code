#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[m];
    for(int i = 0; i < m; ++i) cin >> a[i];
    ll ans = 0;
    int actual = 1;
    for(int i = 0; i < m; ++i) {
        ans += (ll) (a[i] - actual + n) % n;
        actual = a[i];
    }
    cout << ans << '\n';
    return 0;
}