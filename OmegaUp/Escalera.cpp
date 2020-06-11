#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n, k;
ll memoria[10100];
ll solve(ll p) {
    if (memoria[p] != -1) {
        return memoria[p];
    }
    if (p > n) return 0;
    else if (p == n) {
        return 1;
    }
    ll ans = 0;
    for(int i=1; i<=k; ++i) {
        ans += solve(p+i);
    }
    memoria[p] = ans;
    return memoria[p];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0; i<10100; ++i) {
        memoria[i] = -1;
    }
    cin >> n >> k;
    ll ans = solve(0);
    cout << ans << '\n';
    return 0;
}