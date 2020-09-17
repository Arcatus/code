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
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int p1 = 0, p2 = n - 1;
        ll ans = 0;
        bool ok = true;
        auto oraculo = [&](int k, int r) -> pair<int,int> {
            for(int i = k; i >= 1; i--) {
                if(a[i] < 0 ) {
                    for(int j = min(i - 1, r); j >= 0; j--) {
                        if(a[j] > 0) {
                            return {j, i};
                        }
                    }
                }
            }
            return {-1, -1};
        };
        pair<int, int> p = oraculo(n - 1, n - 2);
        while(p.first < p.second) {
            p1 = p.first;
            p2 = p.second;
            if (p1 < p2 && a[p1] > 0 && a[p2] < 0) {
                int d = min(a[p1], -a[p2]);
                a[p1] -= d;
                a[p2] += d;
            }
            p = oraculo(p2, p1);
        } 
        for(int i = 0; i < n; ++i) ans += (ll) (a[i] > 0 ? a[i]: 0);
        //for(int i = 0; i < n; ++i) {cout << a[i] << ' ';} cout << '\n';
        cout << ans << '\n';
    }
    return 0;
}