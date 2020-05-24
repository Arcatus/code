#include <bits/stdc++.h>

using namespace std;
using celda = pair<int, int>;

int n;
bool a[2000];
celda dp[2][2000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x;
    string s;
    while(cin >> s) {
        cin >> n;
            for(int i=0; i<n; ++i) {
                cin >> x;
                a[x-1] = true;
            }
            int z = s.size();
            for(int i=z-1; i>=0; i--) {
                for( int j=0; j<z; ++j ) {
                    if ( i > j ) dp[i&1][j] = { 0, 0 };
                    else if ( i == j ) {
                        dp[i&1][j] = { a[i], 1 };
                    } else {
                        celda r = max(dp[i&1][j-1], dp[(i+1)&1][j]);
                        if ( s[i] == s[j] ) {
                            r = max(r, { a[i] + a[j] + dp[(i+1)&1][j-1].first , 2 + dp[(i+1)&1][j-1].second });
                        }
                        dp[i&1][j] = r;
                    }
                }
            }
            cout << dp[0][z-1].first << " " << dp[0][z-1].second << '\n';
            for(int i=0; i<=z; ++i) a[i] = false;
    }
    return 0;
}