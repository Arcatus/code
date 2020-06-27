// ESTA MAL
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int dp[2][100001] = { };
    int h, w, a, b;
    cin >> h >> w >> a >> b;    
    for(int i=0; i<w; ++i) {
        dp[0][i] = 1;
    }
    dp[1][0] = 1;
    for(int i=1; i<h; ++i) {
        for(int j=0; j<w; ++j) {
            if (j-1 >= 0) dp[i&1][j] = dp[i&1][j-1] + dp[(i-1)&1][j];
            else dp[i&1][j] = dp[(i-1)&1][j];
            if ( h-a <= i && j < b ) dp[i&1][j] = 0;
        }
    }
    cout << dp[(h-1)&1][w-1] << '\n';
    return 0;
}