#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, c;
    cin >> n >> c;
    int w[n];
    for(int i=0; i<n; ++i) cin >> w[i];
    if (n == 1) {
        cout << 1 << '\n';
    } else {
        sort(w, w+n);
        int ans = 0;
        int p1 = 0, p2 = n-1;   
        while( p1 < p2 ) {
            if ( w[p1] + w[p2] <= c ) {
                ans++;
                p2--;p1++;
            } else {
                p2--; ans++;
            }
        }
        if (p1 == p2) ans++;
        cout << ans << '\n';
    }   
    return 0;
}