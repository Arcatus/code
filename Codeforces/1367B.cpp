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
        for(int i = 0;  i < n; ++i) {
            cin >> a[i];
        }
        int p = 0;
        int imp = 0;
        for(int i = 0; i < n; ++i) {
            if(i % 2 != a[i] % 2) {
                if(i % 2 == 0) {
                    p++;
                } else {
                    imp++;
                }
            }
        }
        if(p == imp) {
            cout << p << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
} 