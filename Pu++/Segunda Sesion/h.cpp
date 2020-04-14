#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, x, acc, imp, p;
    cin >> t;
    while(t--)
    {
        cin >> n;
        acc=0, imp=0, p=0;
        for(int i=0; i<n; ++i) {
            cin >> x;
            acc+=x;
            if ( x % 2 == 1 ) {
                imp++;
            } else {
                p++;
            }
        }
        if ( acc % 2 == 1 ) {
            cout << "YES\n";
        } else {
            if ( imp > 0 && p > 0 ) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}