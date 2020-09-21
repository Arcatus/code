#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    ll s;
    while(t--) {
        cin >> s;
        ll ans = 0, tmp;
        while(s > 9) {
            tmp = 10*(s/10);
            ans += tmp;
            s -= tmp;
            s += tmp/10;
        }
        cout << ans + s << '\n';
    }
    return 0;
}