#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, m;
    while(t--) {
        cin >> n >> m;
        int a[n];
        int b[m];
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < m; ++i) cin >> b[i];
        int p1 = 0; 
        int p2 = 0;
        bool ok = false;
        sort(a, a + n);
        sort(b, b + m);
        while(p1 < n && p2 < m) {
            if(a[p1] == b[p2]) {
                ok = true; break;
            }
            if(a[p1] > b[p2]) p2++;
            else if(a[p1] < b[p2]) p1++;
        }
        if(ok) {
            cout << "YES\n";
            cout << 1 << " " << a[p1] << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}