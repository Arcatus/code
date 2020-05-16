#include <bits/stdc++.h>

using namespace std;
/*
vector<int> v;
long long solve(long long k, long long ini) {
    if ( k == n ) {
        for(int i : v) cout << i << ' '; cout << '\n';
        return 1;
    }
    int ans = 0;
    for(int i=ini; i<=n; ++i) {
        if ( k + i <= n ) {
            v.push_back(i);
            ans += solve(k + i, i);
            v.pop_back();
        }
    }
    return ans;
}
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);    
    int n;
    cin >> n;
    //long long ans = solve(0, 1);
    int dp[n+1][n+1] = { };

    for(int i=n; i>=0; i--) { //i->k    j->ini
        for(int j=n; j>=0; j--) {
            if ( i == n ) {
                dp[i][j] = 1;
            } else {
                for(int k=j; k<=n; ++k) {
                    if ( i + k <= n ) {
                        dp[i][j] += dp[i+k][k];
                    }
                }
            }
        }
    }
    /*
    for(int i=0; i<=n; ++i) {
        for(int j=0; j<=n; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    //cout << ans << '\n';
    cout << dp[0][1] << '\n';
    return 0;
}