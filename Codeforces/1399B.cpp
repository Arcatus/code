#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n;
    while(t--) {
        cin >> n;
        ll a[n];
        ll b[n];
        ll mina = INT_MAX;
        ll minb = INT_MAX;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            mina = min(mina, a[i]);
        }
        for(int i = 0; i < n; ++i) {
            cin >> b[i];
            minb = min(minb, b[i]);
        }
        ll ans = 0;
        for(int i = 0; i < n; ++i) {
            if (a[i] > mina && b[i] > minb) {
                int t = min(a[i] - mina, b[i] - minb);
                a[i] -= t;
                b[i] -= t;
                ans += t;
                if(a[i] > mina) {
                    ans += a[i] - mina;
                } else if(b[i] > minb) {
                    ans += b[i] - minb;
                }
            } else {
                if(a[i] > mina) {
                    ans += a[i] - mina;
                }
                if(b[i] > minb) {
                    ans += b[i] - minb;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}