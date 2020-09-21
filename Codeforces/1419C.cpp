#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, x;
    while(t--) {
        cin >> n >> x;
        ll a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] == x) {
                a[i] = 4001; cnt++;
            }
        }
        if(cnt == n) {
            cout << 0 << '\n';
        } else {
            ll t = 0;
            for(int i = 0; i < n; ++i) {
                if(a[i] != 4001) t += x - a[i];
            }
            if(t == 0 || cnt > 0) {
                cout << 1 << '\n';
            } else {
                cout << 2 << '\n';
            }
        }
    }
    return 0;
}