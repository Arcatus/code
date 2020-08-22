#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    int mi = a[0], ma = a[0];
    int ans = 0;
    for(int i = 1; i < n; ++i) {
        if ( a[i] > ma ) {
            ans++;
            ma = a[i];
        }
        if ( a[i] < mi ) {
            ans++;
            mi = a[i];
        }
    }
    cout << ans << '\n';
    return 0;
}