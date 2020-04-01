#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ll n, w;
    cin >> n >> w;

    ll p[n], v[n];

    for(int i=0; i<n; ++i) {
        cin >> p[i] >> v[i];
    }

    ll dp[w+1][n+1];

    for (ll i=w; i>=0; --i) {
        for(ll j=n; j>=0; --j ) {
            if ( j == n ) {
                dp[i][j] = 0;
            } else if ( i + p[j] <= w )  {
                dp[i][j] = max( v[j]+dp[ i+p[j] ][j+1], dp[i][j+1] );
            } else {
                dp[i][j] = dp[i][j+1];
            }
        }
    }
    cout << dp[0][0] << '\n';
}