#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; ++i) cin >> a[i];
    sort(a,a+n);
    int ans = 0;
    for(int i=0; i<n; i+=2) {
        ans += a[i+1] - a[i];
    }
    cout << ans << '\n';
    return 0;
}