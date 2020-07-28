#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    vector<int> b(n);
    b[0] = 1;
    for(int i = 1; i < n; ++i) {
        if ( a[i] - a[i - 1] <= x ) {
            b[i] = b[i - 1] + 1;
        } else {
            b[i] = 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans = max(ans, b[i]);
    }
    cout << ans << '\n';
    return 0;
}