#include <bits/stdc++.h>

using namespace std;

int n, c;
int dp[2][1000000+1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> c;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<=c; ++j) {
            if ( j + a[i] <= c ) {
                dp[i&1][j] = max( a[i] + dp[(i+1)&1][j + a[i]], dp[(i+1)&1][j] );
            } else {
                dp[i&1][j] = dp[(i+1)&1][j];
            }
        }
    }
    cout << dp[0][0] << '\n';
    return 0;
}