#include <bits/stdc++.h>

using namespace std;

long long solve(int n, int b) {
    if ( n == 0 ) {
        return 1;
    } else if (n == 1) {
        return ( b == 2 ) ? 1 : 2;
    } else if (n == 2) {
        return 4 - b;
    }
    if ( b < 2 ) {
        return solve(n-1, 0) + solve(n-1, b+1);
    } else {
        return solve(n-1, 0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long ans = solve(n-1, 0) + solve(n-1,1);
    cout << ans << '\n';
    return 0;
}