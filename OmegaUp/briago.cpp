#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a[1001];
ll memoria[1001][1001];
ll solve(int i, int j) {
    if (memoria[i][j] != -1) 
        return memoria[i][j];
    else if (i == j) {
        memoria[i][j] = a[i];
        return memoria[i][j];
    } else if ( i+1 == j ) {
        memoria[i][j] = max(a[i], a[j]);
        return memoria[i][j];
    }
    memoria[i][j] = max( a[i] + min( solve(i+2,j), solve(i+1,j-1) ), a[j] + min( solve(i,j-2), solve(i+1,j-1) ) );
    return memoria[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            memoria[i][j] = -1;
        }
    }
    ll ans = solve(0,n-1);
    cout << ans << '\n';
    return 0;
}