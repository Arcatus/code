#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int p, q;
    int ans = 0;
    for(int i=0; i<n; ++i) {
        cin >> p >> q;
        if ( q - p >= 2 ) ans++;
    }
    cout << ans << '\n';
    return 0;
}