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
    ll acc, ans = 1LL << 60;
    ll b[n] = { };
    for(int i = 1; i < n; ++i) {
        b[i] = a[i] - a[i - 1];
    }
    ll c[n];
    for(int i = 1; i <= k; ++i) {
        c[i] = i*(k - i);
    }
    for(int j = 0; j <= n - k; ++j) {
        acc = 0;
        for(int i = j + 1, d = 1; i < j + k; ++i, ++d ) {
            acc += c[d]*b[i];
            if(acc > ans) break;
        }
        ans = min(ans, acc);
    }
    cout << ans << '\n';
    return 0;
}