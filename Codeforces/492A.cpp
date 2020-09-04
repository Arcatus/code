#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll cnt = 1;
    int ans = 1;
    while(n - cnt >= 0) {
        n -= cnt;
        ans++;
        cnt = ((ans*(ans + 1))/2);
    }
    cout << ans - 1 << '\n';
    return 0;
}