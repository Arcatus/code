#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n + 2];
    a[0] = INT_MIN;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    a[n + 1] = INT_MAX;
    sort(a, a+n+2);
    int m, x;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        cin >> x;
        int p = upper_bound(a, a + n + 2, x) - a;
        cout << min(abs(x - a[p]), abs(x - a[p - 1])) << '\n';
    }
    return 0;
}