#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n][2];
    for(int i=0; i<n; ++i) {
        cin >> a[i][0] >> a[i][1];
    }
    int dp[n+1] = { };
    for(int i=0; i<n; ++i) {
        if ( i+a[i][0] < n ) dp[i+a[i][0]] = max( dp[i+a[i][0] ], dp[i] + a[i][0]);
        else dp[n] = max(dp[n], dp[i] + a[i][0]);
        if ( i+a[i][1] < n ) dp[i+a[i][1]] = max( dp[i+a[i][1] ], dp[i] + a[i][1]);
        else dp[n] = max(dp[n], dp[i] + a[i][1]);
        dp[i+1] = max(dp[i+1], dp[i] );
    }
    int ans = 0;
    for(int i=0; i<=n; ++i) {
        ans = max(ans, dp[i]);
    } 
    cout << ans << '\n';
    return 0;
}