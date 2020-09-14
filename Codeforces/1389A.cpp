#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    ll l, r;
    while(t--) {
        cin >> l >> r;
        if(2*l <= r) {
            cout << l << " " << 2*l << '\n';
        } else {
            cout << -1 << " " << -1  << '\n';
        }
    }
    return 0;
}