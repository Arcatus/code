#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    string a, b, c;
    while(t--) {
        cin >> a >> b >> c;
        bool ok = true;
        for(int i=0; i<a.size(); ++i) {
            if ( a[i] == c[i] || b[i] == c[i]) {
                continue;
            } else {
                ok = false;
                break;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}