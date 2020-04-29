#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int hi = 0;
    int x;
    int ans = 0;
    for(int i=0; i<n; ++i) {
        cin >> x;
        if ( x < 0 ) {
            x = -x;
            if ( hi >= x ) {
                hi -= x;
            } else {
                x -= hi;
                ans += x;
                hi = 0;
            }
        } else {
            hi += x;
        }
    }
    cout << ans << '\n';
    return 0;
}