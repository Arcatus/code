#include <bits/stdc++.h>

using namespace std;

int n, k;
int memoria[10001][101][7];
int solve(int x, int ini, int lv) {
    if ( memoria[x][ini][lv] != -1 ) {
        return memoria[x][ini][lv];
    } else if (lv > k) {
        memoria[x][ini][lv] = 0;
        return memoria[x][ini][lv];
    } else if ( x == n && lv == k ) {
        memoria[x][ini][lv] = 1;
        return memoria[x][ini][lv];
    }
    memoria[x][ini][lv] = 0;
    for(int i=ini; i*i<=n; ++i) {
        if ( x + i*i <= n ) {
            memoria[x+i*i][i][lv+1] = solve(x + i*i, i, lv+1);
            memoria[x][ini][lv] += memoria[x+i*i][i][lv+1];
        }
    }
    return memoria[x][ini][lv];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    int raiz_n = sqrt(n);
    for(int i=0; i<=n; ++i) {
        for(int j=0; j<=raiz_n; ++j) {
            for(int l=0; l<=k; ++l) {
                memoria[i][j][l] = -1;
            }
        }
    }
    long long ans = solve(0, 1, 0);
    cout << ans << '\n';
    return 0;
}