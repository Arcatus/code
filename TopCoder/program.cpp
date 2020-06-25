#include <bits/stdc++.h>

using namespace std;
int n;
int a[51];
int solve(int ant, int j, bool k) {
    if ( j == n ) return 0;
    if ( k ) {
        int tmp = solve(ant, j+1, k);
        if ( a[j] < ant ) {
            tmp = max(tmp, 1 + solve(a[j], j+1, !k));
        }
        return tmp;
    } else {
        int tmp = solve(ant, j+1, k);
        if ( a[j] > ant ) {
            tmp = max(tmp, 1 + solve(a[j], j+1, !k));
        }
        return tmp;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    int ans = max(solve(0, 0, 0), solve(1001, 0, 1) );
    cout << ans << '\n';
    return 0;
}