#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int b, p, f, h, c, ans;
    while(t--) {
        cin >> b >> p >> f;
        cin >> h >> c;
        ans = 0;
        int pos = b >> 1;
        if ( h > c )  {
            ans += min(pos,p)*h;
            pos -= min(pos,p);
            if ( pos > 0) {
                ans += min(pos,f)*c;
                pos -= min(pos,f);
            }
        } else {
            ans += min(pos,f)*c;
            pos -= min(pos,f);
            if ( pos > 0 ) {
                ans += min(pos,p)*h;
                pos -= min(pos,p);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}