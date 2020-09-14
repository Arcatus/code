#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll ans = n;
    for(int i = n - 1, j = 2; i >= 1; --i, j++) {
        ans += (j*i - (j - 1));
    }
    cout << ans << '\n';
    return 0;
}