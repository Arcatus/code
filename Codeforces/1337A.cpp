#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    ll a, b, c, d;
    while(t--) {
        cin >> a >> b >> c >> d;
        cout << b << " " << c << " " << min(b + c - 1, d) << '\n';
    }
    return 0;
}