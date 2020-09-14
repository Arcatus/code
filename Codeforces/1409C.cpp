#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, x, y;
    while(t--) {
        cin >> n >> x >> y;
        int c = 1;
        int d = (y - x);
        while( d % c != 0 || (n - 1)*c < d ) {
            c++;
        }
        for(int i = 0, j = 1; i < n; ++i) {
            if(y - i*c <= 0) {
                cout << y + j*c << ' '; j++;
            } else {
                cout << y - i*c << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}