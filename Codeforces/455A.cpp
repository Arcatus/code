#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x, n;
    ll v = 100000;
    cin >> n;
    ll a[v + 5] = { };
    for(int i = 0; i < n; ++i) {
        cin >> x;
        a[x]++;
    }
    ll dp[v + 5] = { };
    dp[v + 1] = 0;
    dp[v] = a[v]*v;
    for(int i = v - 1; i >= 1; --i) {
        dp[i] = max(dp[i + 1], dp[i + 2] + a[i]*i);
    }
    cout << dp[1] << '\n';
    return 0;
}