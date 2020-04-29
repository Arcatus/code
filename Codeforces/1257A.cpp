#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, x, a, b;
    while(t--){
        cin >> n >> x >> a >> b;
        if ( a > b ) {
            while(x > 0 && a < n) {
                if ( a < n & x > 0) {
                    a++;
                    x--;
                }
            }
            while(x > 0 && b > 1) {
                if ( b > 1 && x > 0) {
                    b--;
                    x--;
                }
            }
        } else {
            while(x > 0 && b < n) {
                if ( b < n  && x > 0) {
                    b++;
                    x--;
                }
            }
            while(x > 0 && a > 1) {
                if ( a > 1 && x > 0 ) {
                    a--;
                    x--;
                }
            }
        }
        cout << max(a,b) - min(a,b) << '\n';
    }
    return 0;
}