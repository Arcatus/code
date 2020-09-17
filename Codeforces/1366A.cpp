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
        if(a >= 2*b ) {
            cout << b << '\n';
        } else if( b >= 2*a ) {
            cout << a << '\n';
        } else {
            cout << (a + b)/3 << '\n';
        }
    }
    return 0;
}