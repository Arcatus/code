#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (n < 3) {
        cout << 0 << '\n';
        return 0;
    }
    int a[n] = { };
    int x = 0;
    for(int i = 0; i < n; ++i) {
        cin >> x;   
        a[i] = 5 - x;
    }
    sort(a, a + n);
    int ans = 0;
    for(int i = 0; i <= n - 3; i++) {
        if (min(min(a[i], a[i + 1]), a[i + 2]) >= k) {
            ans++;
            a[i] = a[i + 1] = a[i + 2] = 0;
        }        
    }
    cout << ans << '\n';
    return 0;
}