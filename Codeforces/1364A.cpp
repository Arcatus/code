#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, x;
    while(t--) {
        cin >> n >> x;
        ll a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        int p1 = 0, p2 = n - 1;
        ll acc = accumulate(a, a + n, 0);
        if(acc % x == 0) {
            int cnt = 0;
            for(int i = 0; i < n; ++i) {
                if (a[i] % x == 0) cnt++;
            }
            if(cnt == n) {
                cout << -1 << '\n';
            } else {
                ll c[n] = { };
                c[0] = a[0];
                for(int i = 1; i < n; ++i) {
                    c[i] = c[i - 1] + a[i];
                }
                ll d[n] = { };
                d[n - 1] = a[n - 1];
                for(int i = n - 2; i >= 0; i--) {
                    d[i] = d[i + 1] + a[i];
                }
                int ans = 0;
                for(int i = 0; i < n; ++i) {
                    if(c[i] % x != 0) {
                        ans = max(ans, n - i - 1);
                    }
                }
                for(int i = n - 1; i >= 0; i--) {
                    if(d[i] % x != 0) {
                        ans = max(ans, i);
                    }
                }
                cout << ans << '\n';
            }
        } else {
            cout << n << '\n';
        }
    }
    return 0;
}