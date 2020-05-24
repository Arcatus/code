#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[61];
int memoria[21001][61];
const int inf = 1 << 30;
int solve(int k, int i) {
    if ( memoria[k][i] != -1) {
        return memoria[k][i];
    } if ( k >= m || i == n ) {
        memoria[k][i] = 0;
        return memoria[k][i];
    }
    memoria[k+a[i]][i+1] = solve(k+a[i], i+1);
    int x = a[i] + memoria[k+a[i]][i+1];
    memoria[k][i+1] = solve(k, i+1 );
    int y = memoria[k][i+1];
    if ( k + x < m ) x = inf;
    if ( k + y < m ) y = inf;
    return min(x, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<=n*350; ++i) for(int j=0; j<=n; ++j) memoria[i][j] = -1;
    int ans = solve(0,0);
    cout << ans << '\n';
    return 0;
}