#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int dp[n + 1][m + 1] = { };
    for(int i = n; i >= 0; --i) {
        for(int j = m; j >= 0; --j) {
            if (j == m || i == n) {
                dp[i][j] = 0;
            } else if( s[i] == t[j] ) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    int a = 0, b = 0;
    while(a < n && b < m) {
        if (s[a] == t[b]) {
            cout << s[a];
            a++, b++;
        } else {
            if ( dp[a + 1][b] > dp[a][b + 1] ) {
                a++;
            } else {
                b++;
            }
        }
    }
    cout << '\n';
    return 0;
}