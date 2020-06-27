#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    int dp[2][n+1];
    dp[1][n] = dp[0][n] = 0;
    for(int i=0; i<n; ++i) cin >> dp[0][i];
    for(int i=0; i<n; ++i) cin >> dp[1][i];
    for(int i=n-1; i>=0; i--) {
        if (i+s+1 < n) {
            dp[0][i] += max(dp[0][i+1], dp[1][i+s+1]);
            dp[1][i] += max(dp[1][i+1], dp[0][i+s+1]);
        } else {
            dp[0][i] += dp[0][i+1];
            dp[1][i] += dp[1][i+1];
        }
    }
    cout << dp[0][0] << '\n';
    bool t = 0; int m = 0;
    while(m < n) {
        cout << ( !t ? 'A':'B') << " " <<  m << '\n';
        if(m+s+1 < n) {
            if ( dp[t][m+1] > dp[!t][m+s+1] ) m++;
            else {
                t = !t;
                m = m+s+1;
            }
        } else {
            m++;
        }
    }
    return 0;
}