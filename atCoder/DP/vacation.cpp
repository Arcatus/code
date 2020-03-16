#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n][3];

    for(int i=0; i<n; ++i) {
        for(int j=0; j<3; ++j) {
            cin >> a[i][j];
        }
    }
    
    int dp[n][3];
    
    for(int i=0; i<3; ++i) {
        dp[0][i] = a[0][i];    
    }
    
    for(int i=1; i<n; ++i ) {
        for(int j=0; j<3; ++j) {
            int optimo = -1;    
            for( int k=0; k<3; ++k ) {
                if ( j == k ) continue;
                optimo = max(optimo, dp[i-1][k]);
            }
            dp[i][j] = optimo + a[i][j];
        }
    }
    cout << *max_element( dp[n-1], dp[n-1]+3 ) << '\n';
}