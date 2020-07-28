#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    bool a[n+1] = { };
    int x;
    for(int i=0; i<n-1; ++i) {
        cin >> x;
        a[x] = true;
    }
    for(int i=1; i<=n; ++i) {
        if ( !a[i] ) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}