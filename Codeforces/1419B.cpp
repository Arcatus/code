#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    ll x;
    ll n;
    while(t--) {
        cin >> x;
        int ans = 0;
        if(x == 1) {
            cout << 1 << '\n';
        } else {
            int ans = 0;
            ll pow = 1LL; int k = 1;
            while(x > 0) {
                ans++;
                x -= ((1LL << k) - 1)*(1LL << (k - 1)); k++;
            }
            cout << ans - ( x < 0 ? 1: 0 ) << '\n';
        }
    }
    return 0;
}