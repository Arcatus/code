#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll b[n];
    for(int i = 0; i < n; ++i) cin >> b[i];
    ll a[n];
    a[0] = b[0];
    ll maxv = max(a[0], 0LL);
    for(int i = 1; i < n; ++i) {
        a[i] = b[i] + maxv;
        maxv = max(maxv, a[i]);
    }
    for(int i = 0; i < n; ++i) cout << a[i] << ' '; cout << '\n';
    return 0;
}