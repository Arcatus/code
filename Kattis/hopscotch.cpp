#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <limits.h>
#include <algorithm>

using namespace std;

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    vector< vector< pair< int, int> > >  reach (n*n+1);

    int val;

    for( int i=1; i<=n; ++i  ) {
        for( int j=1; j<=n; ++j  ) {
            cin >> val;
            reach[ val ].push_back( {i, j} );
        }
    }

    vector< vector<int> > dp(k+1);

    for( int i=0; i<reach[1].size(); ++i ) {
        dp[1].push_back(0);
    }
    for( int i=2; i<=k; ++i ) {
        for(int j=0; j<reach[i].size(); ++j ) {
            dp[i].push_back( INT_MAX );
            for(int k=0; k<reach[i-1].size(); ++k ) {
                dp[i][j] = min( dp[i-1][k] + abs( reach[i][j].first - reach[i-1][k].first ) 
                            + abs( reach[i][j].second - reach[i-1][k].second ), dp[i][j] );
            }
        }
    }

    int ans = INT_MAX;

    for(int i=0; i<dp[k].size(); ++i) {
        if ( dp[k][i] < ans ) ans = dp[k][i];
    }
    
    if ( ans == INT_MAX || ans < 0 ) {
        cout << -1;
    } else {
        cout << ans;
    }
}