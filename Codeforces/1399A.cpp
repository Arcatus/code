#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;   
    int n;
    while(t--) {
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);
        bool ok = true;
        for(int i = 1; i < n; ++i) {
            if (a[i] - a[i - 1] > 1) {
                ok = false; break;
            }
        }
        cout << (ok ? "YES\n":"NO\n");
    }
    return 0;
}