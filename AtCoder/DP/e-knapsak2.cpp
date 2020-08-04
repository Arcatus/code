#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, w, m = 0;
    cin >> n >> w;
    ll p[n], v[n];
    for(int i = 0; i < n; ++i) {
        cin >> p[i] >> v[i];
        m += v[i];
    }
    ll dp[m + 1];
    for(int i = 0; i <= m; ++i) dp[i] = INT_MAX;
    dp[0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = m; j >= v[i]; --j) {
            dp[j] = min(dp[j], dp[j - v[i]] + p[i] );
        }
    }
    ll ans = 0;
    for(int i = m; i >= 0; i-- ) {
        if (dp[i] <= w) {
            ans = i; break;
        }
    }
    cout << ans << '\n';
    return 0;
}
