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
        if (n == 1) {
            cin >> n;
            cout << 0 << '\n';
            continue;
        }
        int a[n];
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int p1 = 0, p2 = n - 1;
        while(p2 >= 1) {
            if (a[p2] <= a[p2 - 1]) p2--;
            else break;
        }
        int ans = 0;
        while(p1 < p2 && p1 < n) {
            if (a[p1] <= a[p1 + 1] ) p1++;
            else {
                ans = p1 + 1;
                p1++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}