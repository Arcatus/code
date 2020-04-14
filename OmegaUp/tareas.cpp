#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    double a, b, h;
    cin >> a >> b >> h;
    double ans = ( (a + b) / 2.0) * h ;
    cout << fixed << ans << '\n';
    return 0;
}
