#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll dp[1000000 + 5];
    for(int i = 0; i < n; ++i) dp[i] = INT_MIN;
    dp[0] = 0;
    ll c[] = {1, 4, 5, 7, 8, 9};
    ll v[] = {2, 4, 5, 3, 7, 6};
    for(int i = 2; i <= n; ++i) {
        ll ans = INT_MIN;
        for(int j = 0; j < 6; ++j) {
            if (i - v[j] >= 0) {
                ans = max(ans, c[j] + dp[i - v[j]]);
            }
        }
        dp[i] = ans;
    }
    cout << dp[n] << '\n';
    return 0;
}