#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long a[n+1], b[n+1], c[n+1];
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<n; ++i) cin >> b[i];
    for(int i=0; i<n; ++i) cin >> c[i];
    long long m, x;
    cin >> m;
    for(int i=0; i<m; ++i) {
        cin >> x;
        int p = lower_bound(a,a+n,x) - a;
        if ( x < a[0]) cout << 0 << ' ';
        else if ( x > a[n-1]) cout << n << ' ';
        else {
            if ( x == a[p] ) {
                cout << p+1 << ' ';
            } else {
                cout << p << ' ';
            }
        }
        p = lower_bound(b,b+n,x) - b;
        if ( x < b[0]) cout << 0 << ' ';
        else if ( x > b[n-1]) cout << n << ' ';
        else {
            if ( x == b[p] ) {
                cout << p+1 << ' ';
            } else {
                cout << p << ' ';
            }
        }
        p = lower_bound(c,c+n,x) - c;
        if ( x < c[0]) cout << 0 << ' ';
        else if ( x > c[n-1]) cout << n << ' ';
        else {
            if ( x == c[p] ) {
                cout << p+1 << ' ';
            } else {
                cout << p << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}