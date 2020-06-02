#include <bits/stdc++.h>

using namespace std;
int a, b, c, n;
int solve(int k) {
    if (k == 1) return c;
    return a*solve(k/2) + b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c >> n;
    int ans = solve(n);
    cout << ans << '\n';
    return 0;
}