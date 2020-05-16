#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    long long n, k;
    while(t--) {
        cin >> n >> k;
        long long bkt = (n-1);
        long long z = k / bkt;
        if ( k % bkt == 0 ) { 
            z--;
            long long ans = z*bkt + z + ((k-1)%bkt+1);
            cout << ans << '\n';
        } else {
            long long ans = z*bkt + z + (k%bkt);
            cout << ans << '\n';
        }
    }
    return 0;
}