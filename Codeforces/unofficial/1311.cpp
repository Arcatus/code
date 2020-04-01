#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
    int a, b;
    cin >> a >> b;
        
    int t = abs( b - a );
    if ( a == b ) cout << 0 << '\n';
    else if ( a > b ) {
        if ( t % 2 == 1 ) {
            cout << 2 << '\n';
        } else {
            cout << 1 << '\n';
        }
    } else {
        if ( t % 2 == 1 ) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    }
    return 0;
}