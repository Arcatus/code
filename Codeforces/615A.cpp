#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x, k;
    cin >> n >> m;
    bool ans[m+1] = { };
    while(n--) {
        cin >> x;
        for(int i=0; i<x; ++i) {
            cin >> k;
            ans[k] = true;
        }
    }
    for(int i=1; i<=m; ++i) {
        if ( !ans[i] ) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}