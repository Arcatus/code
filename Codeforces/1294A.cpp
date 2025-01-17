#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a[3], n;
        cin >> a[0] >> a[1] >> a[2] >> n;
        sort(a, a + 3);
        if ( a[0] - a[1] <= n ) {
            n -= (a[1] - a[0]);
            a[0] = a[1];
            if(2*(a[2] - a[0]) <= n) {
                n -= 2*(a[2] - a[0]);
                if (n % 3 == 0) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";                    
                }
            } else {
                cout << "NO\n";                
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}