#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll n, k, d;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> d;
    ll dp[101][2] = { };
    dp[0][0] = 1;
    for(int i=0; i<n; ++i) {
        for(int j=1; j<=k; ++j) {
            if ( i + j <= n ) {
                if ( d <= j ) {
                    dp[i + j][1] = (dp[i + j][1]%mod)+(dp[i][0]%mod);
                } else {
                    dp[i + j][0] = (dp[i + j][0]%mod)+(dp[i][0]%mod);
                }
            }
        }
    }
    for(int i=0; i<n; ++i) {
        if (dp[i][1] > 0 ) {
            for(int j=1; j<=k; ++j) {
                if ( i+j <= n) {
                    dp[i+j][1] = (dp[i+j][1]%mod)+(dp[i][1]%mod)%mod;
                }
            }
        }
    }
    cout << dp[n][1] % mod << '\n';
    return 0;   
}