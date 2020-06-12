#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    double a[n] = { };
    long long x, y;
    for(int i=0; i<n; ++i) {
        cin >> x >> y;
        a[i] = (double) hypot(x,y);
    }
    sort(a, a+n);
    double ans = 0.0;
    for(int i=0; i<r; ++i) {
        ans += a[i];
    }
    ans = ans*2.0;
    double decimals = ans - (int(ans));
    if (decimals <= 0.5) {
        cout << int(ans) << '\n';
    } else {
        cout << int(ans)+1 << '\n';
    }
    return 0;
}