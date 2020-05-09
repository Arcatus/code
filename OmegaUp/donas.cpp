#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    int x;
    for(int i=0; i<n; ++i) {
        cin >> x;
        bool ok = false;
        for(int j=0; j<=150 && !ok; ++j ) {
            for(int k=0; k<=150 && !ok; ++k ) {
                if ( ( a*j + b*k ) == x ) {
                    ok = true;
                }
            }
        }
        if (ok) cout << "Si\n";
        else cout << "No\n";
    }
    return 0;
}