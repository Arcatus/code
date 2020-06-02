#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    cout << a[1]-a[0] << " " << a[n-1] - a[0] << '\n';
    for(int i=1; i<n-1; ++i) {
        cout << min( a[i+1] - a[i], a[i] - a[i-1] ) << ' ';
        cout << max( a[i] - a[0], a[n-1]-a[i] ) << '\n';
    }
    cout << a[n-1]-a[n-2] << " " << a[n-1] - a[0] << '\n';
    return 0;
}