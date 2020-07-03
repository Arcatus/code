#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i=0; i<n; ++i) {
        for(int j=i; j<n; ++j) {
            int tmp = 0;
            for(int k=0; k<n; ++k) {
                if ( i <= k && k <= j ) {
                    tmp += (a[k]==0);
                } else {
                    tmp += (a[k]==1);
                }
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << '\n';
    return 0;
}