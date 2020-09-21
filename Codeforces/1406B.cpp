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
        ll a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);    
        ll ans = 0;
        ans = max(a[n - 1]*a[n - 2]*a[n - 3]*a[n - 4]*a[n - 5], a[0]*a[1]*a[2]*a[3]*a[n - 1]);
        ans = max(ans, a[0]*a[1]*a[n - 1]*a[n - 2]*a[n - 3]);
        cout << ans << '\n';
    }
    return 0;
}