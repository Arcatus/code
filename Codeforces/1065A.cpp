#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    ll s, a, b, c;
    while(t--) {
        cin >> s >> a >> b >> c;
        cout << ((s/c)/a)*b + s/c << '\n';
    }
    return 0;
}