#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAX 1000000001

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, w;
    
    cin >> n >> w;
    ll p[n+1], v[n+1];

    int max_v = 0;
    for(int i=0; i<n; ++i) {
        cin >> p[i] >> v[i];
        max_v += v[i];
    }
    
    ll dp[n+1][max_v+1];

    for(int i=n; i>=0; --i) {
        for(int j=0; j<=max_v; ++j) {
            if ( i == n ) {
                dp[i][j] = MAX;
            } else if( j - v[i] >= 0 ) {
                dp[i][j] = min( p[i] + ((j-v[i]==0)? 0 : dp[i+1][j-v[i]]), dp[i+1][j]) ;
            } else {
                dp[i][j] = dp[i+1][j];
            }
        }
    }
    ll ans = -1;
    for(int i=0; i<=max_v; ++i) {
        for(int j=0; j<=n; ++j) {
            if ( dp[j][i] <= w ) {
                ans = i;
            }
        }
    }
    cout << ans << '\n';
}