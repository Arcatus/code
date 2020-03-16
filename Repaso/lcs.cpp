#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string x, y;
/*
int lcs(int a, int b) {
    if ( a == x.size() || b == y.size() ) {
        return 0;
    }
    if ( x[a] == y[b] ) {
        return lcs(a + 1, b + 1) + 1;
    } else {
        return max(lcs(a+1, b), lcs(a, b+1));
    }
}
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y;
    
    if ( x.size() <= 1000 && y.size() <= 1000 ) {
        
        int dp[x.size()+1][y.size()+1];

        for(int i=x.size(); i>=0; --i ) {
            for(int j=y.size(); j>=0; --j ) {
                if ( i == x.size() || j == y.size() ) {
                    dp[i][j] = 0;
                } else if ( x[i] == y[j] ){
                    dp[i][j] = dp[i+1][j+1] + 1;
                } else {
                    dp[i][j] = max( dp[i][j+1], dp[i+1][j] );
                }
            }
        }
        
        int i=0, j=0;
        cout << dp[0][0] << '\n';

        while( i < x.size() && j < y.size() ) {
            if ( x[i] == y[j] ) {
                cout << i << " " << j << '\n';
                i++; j++;
            } else if ( dp[i][j+1] > dp[i+1][j] ) {
                j++;
            } else {
                i++;
            }
        }
    } else {
        
        int dp[2][y.size()+1];

        int *actual = dp[0];
        int *anterior = dp[1];

        for(int i=x.size(); i>=0; --i ) {
            for(int j=y.size(); j>=0; --j ) {
                if ( i == x.size() || j == y.size() ) {
                    actual[j] = 0;
                } else if ( x[i] == y[j] ) {
                    actual[j] = anterior[j+1] + 1;
                } else {
                    actual[j] = max( actual[j+1], anterior[j] );
                }
            }
            swap(actual, anterior);
        }
        cout << anterior[0] << '\n';
    }
}