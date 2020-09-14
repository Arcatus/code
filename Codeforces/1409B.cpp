#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    ll a, b, x, y, n;
    while(t--) {
        cin >> a >> b >> x >> y >> n;
        if( max(a - n, x) < max(b - n, y) ) {
            int t = min(a - x, n);
            a -= t;
            n -= t;
            assert(n >= 0);
            if(n > 0) {
                b = max(b - n, y);
            }
        } else {
            int t = min(b - y, n);
            b -= t;
            n -= t;
            assert(n >= 0);
            if(n > 0) {
                a = max(a - n, x);
            }
        }
        cout << a*b << '\n';
    }
    return 0;
}