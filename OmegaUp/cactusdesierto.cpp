#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, x;
    cin >> n;
    int c[n];
    for(int i=0; i<n; ++i) cin >> c[i];
    sort(c, c+n);
    cin >> m;
    for(int i=0; i<m; ++i) {
        cin >> x;
        int p = lower_bound(c,c+n,x) - c;
        if ( p == 0 ) {
            cout << c[0] - x << ' ';
        } else if (p == n) {
            cout << x - c[n-1] << ' ';
        } else {
            if (c[p] == x) cout << 0 << ' ';
            else cout << c[p] - c[p-1] << ' ';
        }
    }
    cout << '\n';
    return 0;
}