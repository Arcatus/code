#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    int a[n - 1] = { };
    for(int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }
    int pos = 0;
    while(pos < n - 1) {
        if(pos == t - 1) break;
        pos += a[pos];
    }

    cout << (pos == t - 1 ? "YES\n" : "NO\n");
    return 0;
}