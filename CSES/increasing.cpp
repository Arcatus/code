#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    long long ans = 0;
    cin >> a[0];
    for(int i=1; i<n; ++i) {
        cin >> a[i];
        if ( a[i] < a[i-1] ) {
            ans += (long long) a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout << ans << '\n';
    return 0;
}
