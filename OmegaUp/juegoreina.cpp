#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    int a[m+1];
    for(int i=1; i<=m; ++i) {
        cin >> a[i];        
    }
    int n, x;
    cin >> n;
    int ans;
    for(int i=0; i<n; ++i) {
        cin >> x;
        int lo = 1, hi = m;        
        while(lo != hi) {
            int f = lo + (hi-lo)/2;
            if ( f <= a[f] + x ) {
                hi = f;
            } else {
                lo = f+1;
            }
        }
        int l = lo, r = m;
        if ( lo != a[lo] + x ) {
            cout << 0 << ' ';
        } else {
            while( l != r ) {
                int f = l + (r-l)/2+1;
                if ( f == a[f]+x ) {
                    l = f;
                } else {
                    r = f-1;
                }
            }
            cout << l - lo + 1 << ' ';
        }
    } cout << '\n';
    return 0;
}