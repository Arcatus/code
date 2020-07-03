#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long x, y, n;
    int t;
    cin >> t;
    while(t--) {
        cin >> x >> y >> n;
        cout << ((n-y)/x)*x + y << '\n';
    }
    return 0;
}