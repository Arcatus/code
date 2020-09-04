#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x, n;
    cin >> n >> x;
    ll ans = 0;
    for(ll i = 1 ; i <= n; ++i) {
        if(x % i == 0 && i <= x && x <= n*i ) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}