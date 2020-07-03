#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    int c[n];
    c[0] = a[0];
    for(int i=1; i<n; ++i) {
        c[i] = a[i] + c[i-1];
    }    
    int m, x;
    cin >> m;
    for(int i=0; i<m; ++i) {
        cin >> x;
        int p = lower_bound(c,c+n,x) - c;
        cout << p+1 << '\n';
    }    
    return 0;
}