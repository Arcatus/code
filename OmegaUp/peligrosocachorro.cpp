#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, e, a;
    cin >> n >> e >> a;
    int arr[n];
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
    }

    int dp[500+10] = { };
    dp[250] = e; 
    bool visited[500+10] = { };
    visited[250] = true;
    if ( a == 0 ) {
        cout << 0 << '\n';
    } else {
        int times = 250;
        while(times--) {
            for(int i=250; i<=500; ++i) {
                if ( dp[i] > 0 ) {
                    for(int j=0; j<n; ++j) {
                        if ( dp[i] >= arr[j] ) {
                            dp[ i - arr[j] ] = max(dp[ i - arr[j] ], dp[i] - arr[j]);
                            dp[ i + arr[j] ] = max(dp[ i + arr[j] ], dp[i] - arr[j]);
                            visited[ i - arr[j] ] = true;
                            visited[ i + arr[j] ] = true;
                        }
                    }
                }
            }
        }
        if ( visited[a + 250] ) {
            cout << e - dp[a+250] << '\n'; 
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}