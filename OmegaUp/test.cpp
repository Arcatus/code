#include <bits/stdc++.h>

using namespace std;
/*
vector<int> v;
int n, k;
long long solve(long long x, long long ini, int lv) {
    if (lv > k) return 0;
    if ( x == n && lv == k ) {
        return 1;
    }
    int ans = 0;
    for(int i=ini; i*i<=n; ++i) {
        if ( x + i*i <= n ) {
            v.push_back(i);
            ans += solve(x + i*i, i, lv+1);
            v.pop_back();
        }
    }
    return ans;
}
*/

int dp[10001][101][7];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);    
    int n, k;
    cin >> n >> k;
    //long long ans = solve(0, 1, 0);
    //cout << ans << '\n';
    for(int i=n; i>=0; i--) {
        for( int j=sqrt(n); j>=0; j-- ) {
            for( int l=k+1; l>=0; l-- ) {
                if ( l == k+1 ) {
                    dp[i][j][l] = 0;
                } else if ( i == n && l == k ) {
                    dp[i][j][l] = 1;
                } else {
                    for(int m=j; m*m <= n; ++m) {
                        if( i + m*m <= n ) {
                            dp[i][j][l] += dp[i+m*m][m][l+1];
                        }
                    }
                }
            }   
        }
    }
    /*
    for(int i=0; i<=n; ++i) {
        for(int j=0; j<=sqrt(n); ++j) {
            for(int l=0; l<=k; ++l) {
                cout << "( "<< i << " " << j << " "<< l << " ) = " << dp[i][j][l] << '\n';
            }
        }
    }
    */
    cout << dp[0][1][0] << '\n';
    return 0;
}