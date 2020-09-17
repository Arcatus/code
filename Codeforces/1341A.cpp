#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int x = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, a, b, c, d;
    while(t--) {
        cin >> n >> a >> b >> c >> d;
        int l = max((a - b)*n, c - d );
        int r = min((a + b)*n, c + d );
        if( l <= r) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}