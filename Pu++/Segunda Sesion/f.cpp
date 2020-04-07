#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n+1];
    for(int i=1; i<=n; ++i) cin >> a[i];
    int ans = -1;
    for(int i=1; i <= k; ++i) {
        int b[n+1];
        copy(a, a+n+1, b);
        for(int j=i; j<=n; j+=k) {
            b[j] = 0;
        }
        int m1=0, m2=0;
        for(int j=1; j<=n; ++j ) {
            if (b[j] == 1) {
                m1++;
            } else if ( b[j] == -1) {
                m2++;
            }
        }
        ans = max(ans, abs(m2-m1));
    }
    cout << ans << '\n';
    return 0;
}