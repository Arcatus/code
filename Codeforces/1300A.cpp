#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n;
    while(t--) {
        cin >> n;
        int ans = 0;
        int acc = 0;
        int x;
        for(int i=0; i<n; ++i) {
            cin >> x;
            if ( x == 0 ) {
                ans++;
                acc += 1;
            }
            acc += x;
        }
        if ( acc == 0 ) {
            cout << ans +1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}