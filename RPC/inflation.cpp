#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    double a[n];
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);
    double ans = 1.0;
    for(int i=1; i<=n; ++i) {
        if ( a[i-1] <= i ) {
            ans = min( ans, a[i-1] / i);
        } else {
            cout << "impossible\n";
            return 0;
        }
    }
    cout.precision(6);
    cout << fixed;
    cout << ans << '\n';
    return 0;
}