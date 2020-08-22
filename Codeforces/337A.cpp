#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[m + 1] = { };
    for(int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    sort(a, a + m + 1);
    int ans = INT_MAX;
    for(int i = n; i <= m; ++i) {
        ans = min(ans, a[i] - a[i - n + 1]);
    }
    cout << ans << '\n';
    return 0;
}