#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll x, y;
        cin >> x >> y;
        ll a, b;
        cin >> a >> b;
        ll ans = 0;
        ans += min(b*min(x, y), 2*a*min(x, y));
        ll tmp = min(x, y);
        x -= tmp;
        y -= tmp;
        ans += a*x + a*y;
        cout << ans << '\n';
    }
    return 0;
}