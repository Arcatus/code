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
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);
        int ans = 1 << 30;
        for(int i = 1; i < n; ++i) {
            ans = min(ans, abs(a[i] -  a[i - 1]));
        }
        cout << ans << '\n';
    }   
    return 0;
}