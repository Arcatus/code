#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, p=0, c=0;
    while(t--) {
        cin >> n;
        bool ok = true;
        int a[n], b[n];
        for(int i=0; i<n; ++i) {
            cin >> a[i] >> b[i];
        }
        if ( a[0] < b[0] ) {
            ok = false;
        }
        for(int i=1; i<n && ok; ++i) {
            if ( a[i] < a[i - 1] || b[i] < b[i - 1] || a[i] < b[i] ) {
                ok = false;
            } else {
                if ( b[i] - b[i - 1] > a[i] - a[i - 1]  ) {
                    ok = false;
                }
            }
        }
        if(ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }   
    }
    return 0;
}