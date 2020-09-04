#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    ll n;
    while(t--) {
        cin >> n;
        if(n == 1) {
            cout << 0 << '\n';
        } else {
            ll ans = 0;
            ll f = n/2;
            while(f > 0) {
                ans += (ll) 2*n*f + 2*f*(n - 2);
                n -= 2;
                f = n / 2;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}