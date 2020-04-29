#include <bits/stdc++.h>

using namespace std;

int solve(int k) {
    if ( k == 1 ) {
        return 1;
    } else if ( k == 3) {
        return 3;
    } else if ( k%2 == 0 ) {
        return solve(k/2);;
    } else if ( (k-1) % 4 == 0 ) {
        int n = (k - 1) / 4;
        return 2*solve(2*n+1) - solve(n);
    } else {
        int n = (k - 3) / 4;
        return 3*solve(2*n+1) - 2*solve(n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = solve(n);
    cout << ans << '\n';
    return 0;
}