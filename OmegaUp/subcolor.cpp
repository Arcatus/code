#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define OFFSET 10000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    int sum = accumulate(a, a+n, 0);
    long long dp[2][20000+5] = { };
    for(int i=0; i<2; ++i) {
        dp[i][OFFSET] = 1LL;
    }
    int i;
    long long ans = dp[0][OFFSET];
    for(i=0; i<n; ++i ) {
        for(int j=-sum+OFFSET; j<=sum+OFFSET; ++j) {
            if ( dp[i & 1][j] > 0 ) {
                dp[(i+1) & 1][j-a[i]] += (dp[i & 1][j] % mod);
                dp[(i+1) & 1][j+a[i]] += (dp[i & 1][j] % mod);
                dp[i&1][j] = (j == OFFSET) ? 1 : 0;
            }
        }
        ans += dp[(i+1) & 1][OFFSET];
    }
    cout << (ans - n - 1) % mod << '\n';
    return 0;
}