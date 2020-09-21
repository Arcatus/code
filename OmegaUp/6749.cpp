#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    ll diff = 1LL << 60, x;
    for(int i=0; i <= n - k; ++i) {
        if ( (a[i + k - 1] - a[i]) < diff ) {
            diff = a[i + k - 1] - a[i];
            x = i;
        }
    }
    ll b[n] = { };
    for(int i = 1; i < n; ++i) {
        b[i] = a[i] - a[i - 1];
    }
    ll c[n];
    for(int i = 1; i <= k; ++i) {
        c[i] = i*(k - i);
    }
    ll ans = 1LL << 60;
    bool randomized[n + 1] = { };
    ll times = 0;
    srand(time(NULL));
    while(times < min(n - k, 200LL)) {
        int r = rand() % (n - k);
        if(!randomized[r]) {
            randomized[r] = true;
            ll tmp = 0;            
            for(int i = r + 1, d = 1; i < r + k; ++i, ++d ) {
                tmp += c[d]*b[i];
            }
            ans = min(ans, tmp);
            times++;
        } else continue;
    }
    /*
    for(int i = x + 1, d = 1; i < x + k; ++i, ++d ) {
        ans += c[d]*b[i];
    }
    */
    cout << ans << '\n';
    return 0;
}