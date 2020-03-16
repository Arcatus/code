#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    int h[n+5];
    
    for (int i=1; i<=n; ++i) {
        cin >> h[i];
    }

    int dp[n+1];

    dp[0] = dp[1] = 0;

    for(int i=2; i<=min(k+1,n); ++i) {
        dp[i] = abs( h[1] - h[i] );
    }

    for(int i=k+2; i<=n; ++i) {
        int ans = INT_MAX;
        for(int j=1; j <= k; j++) {
            ans = min(ans, abs(h[i] - h[i-j]) + dp[i-j]);
        }
        dp[i] = ans;
    }
    cout << dp[n] << '\n';
}