#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int bkt[1000000 + 1] = { };
    int n, x;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        bkt[a[i]]++;
    }
    int acc[n] = { };
    acc[0] = a[0];
    for(int i = 1; i < n; ++i) acc[i] = acc[i - 1] + a[i];
    ll ans = 0;
    for(int i = 0; i < n - 1; ++i) {
        ll tmp = (ll) ((acc[n - 1] - acc[i]) - a[i]*(n - i - 1));
        ll tmp2 = (ll) -bkt[a[i] + 1] + bkt[a[i] - 1];
        ans += tmp + tmp2;
        bkt[a[i]]--;
    }
    cout << ans << '\n';
    return 0;
}