#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, x;
    while(t--) {
        cin >> n;
        int a[n + 1] = { };
        for(int i = 0; i < n; ++i) {
            cin >> x;
            a[x]++;
        }
        int ans = a[1], tmp;
        for(int i = 2; i <= n; ++i) {
            ans += a[i] / i;
            a[i + 1] += a[i] % i;
        }
        cout << ans << '\n';
    }
    return 0;
}