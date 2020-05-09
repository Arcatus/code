#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    int ans = 0;
    if ( a[2] < n ) {
        ans++;
        n = a[2];
    }
    if ( a[1] < n ) {
        ans++;
        n = a[1];
    }
    if ( a[0] < n ) {
        ans++;
        n = a[0];
    }
    cout << ans << '\n';

    return 0;
}