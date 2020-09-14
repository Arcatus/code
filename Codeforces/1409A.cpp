#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    ll a, b;
    while(t--) {
        cin >> a >> b;
        cout << abs(a - b)/10 + ( abs(a - b) % 10 > 0 ) << '\n';
    }
    return 0;
}