#include <iostream>
#include <vector>

using namespace std;
/* ver 1
int minPathSum(vector<vector<int>>& grid) {
    int x = grid.size();
    int y = grid[0].size();
    int dp[x+1][y+1];

    dp[0][0] = grid[0][0];

    for(int i=1; i<x; ++i) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for(int i=1; i<y; ++i) {
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }

    for(int i=1; i<x; ++i) {
        for(int j=1; j<y; ++j) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1] ) + grid[i][j];
        }
    }
    return dp[x-1][y-1];
}
*/

int minPathSum(vector<vector<int>>& grid) {
    int x = grid.size();
    int y = grid[0].size();
    
    int dp[2][y+1];

    int *actual = dp[0];
    int *anterior = dp[1];

    for(int i=0; i<x; ++i) {
        for(int j=0; j<y; ++j) {
            if( i == 0 && j == 0 ) {
                actual[j] = grid[0][0];
            } else if ( i == 0 ) {
                actual[j] = actual[j-1] + grid[i][j];
            } else if ( j == 0 ) {
                actual[j] = anterior[j] + grid[i][j];
            } else {
                actual[j] = min(actual[j-1], anterior[j] ) + grid[i][j];
            }
        }
        swap(actual, anterior);
    }
    return anterior[y-1];
}


int main()
{
    int m, n;
    cin >> m >> n;
    int x;
    vector< vector<int> > grid(m);

    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> x;
            grid[i].push_back(x);
        }
    }
    int ans = minPathSum( grid );

    cout << ans << '\n';
}