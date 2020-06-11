#include <bits/stdc++.h>

using namespace std;
int m, k;
int a[101];
int memoria[100+1][100+1];
int solve(int i, int g) {
    if ( memoria[i][g] != -1) {
        return memoria[i][g];
    }
    else if ( i == k ) return 0;
    memoria[i][g] = max( (g+a[i])%m + solve(i+1,(g+a[i])%m), (g*a[i])%m + solve(i+1,(g*a[i])%m) );
    return memoria[i][g];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> k;
    for(int i=0; i<k; ++i) cin >> a[i];
    for(int i=0; i<101; ++i)
    for(int j=0; j<101; ++j)
        memoria[i][j] = -1;
    int ans = solve(0,0);
    cout << "Al final me puedo quedar con " << ans << " monedas." << '\n';
    return 0;
}