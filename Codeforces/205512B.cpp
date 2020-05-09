#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, x;    
    cin >> n >> k;
    if ( k >= n ) {                
        int ans = 1 << 30;
        for(int i=0; i<n; ++i) {
            cin >> x;
            ans = min(ans,x);
        }   
        cout << ans << ' ';
    } else {
        if (n%k == 0) {
            for(int i=0; i<(n/k); ++i) {
                int ans = 1 << 30;
                for(int j=0; j<k; ++j) {
                    cin >> x;
                    ans = min(ans,x);
                }
                cout << ans << ' ';
            }   
        } else {
            for(int i=0; i<(n/k); ++i) {
                int ans = 1 << 30;
                for(int j=0; j<k; ++j) {
                    cin >> x;
                    ans = min(ans,x);
                }
                cout << ans << ' ';
            }
            int ans = 1 << 30;
            for(int j=0; j<(n%k); ++j) {
                cin >> x;
                ans = min(ans,x);
            }
            cout << ans << ' ';
        }
    } cout << '\n';
    return 0;
}