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

    if ( n <= 2 ) {
        cout << n << '\n';
    } else {
        int ans = 2, local = 2;
        for(int i=2; i<n; ++i) {
            if ( a[i] == a[i-1] + a[i-2] ) {
                local++;
            } else {
                ans = max( ans, local);
                local = 2;
            }
        }
        cout << max(ans, local) << '\n';
    }

    return 0;
}