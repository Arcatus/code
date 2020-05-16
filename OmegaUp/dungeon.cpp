#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, v;
    cin >> n >> m >> v;
    int mat[n][m] = { };
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin >> mat[i][j];
        }
    }
    int x, y;
    cin >> x >> y; x--; y--;
    int dp[2][m];
    for(int i=0; i<2; ++i) for(int j=0; j<m; ++j) dp[i][j] = 0;
    int i = 1;
    for(; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if ( j == 0 ) {
                dp[i&1][j] = mat[i][j] + min(dp[(i-1)&1][j],dp[(i-1)&1][j+1]);    
            } else if ( j == m-1 ) {
                dp[i&1][j] = mat[i][j] + min(dp[(i-1)&1][j-1],dp[(i-1)&1][j]);    
            } else {
                dp[i&1][j] = mat[i][j] + min(dp[(i-1)&1][j-1],min(dp[(i-1)&1][j],dp[(i-1)&1][j+1]));
            }
        }
    }
    if ( v - dp[(i-1)&1][y] > 0 ) {
        cout << v - dp[(i-1)&1][y] << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}