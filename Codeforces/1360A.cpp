#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int a, b;
    while(t--) {
        cin >> a >> b;
        if (a == b) {
            cout << (2*a)*(2*b) << '\n';
        } else {
            int x = max(a, b);
            int y = min(a, b);
            int w = max(2*y, x);
            int z = min(2*y, x);
            cout << (abs(w - z) + z)*(abs(w - z) + z) << '\n';
        }
    }
    return 0;
}