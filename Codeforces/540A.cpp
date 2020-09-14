#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string x, y;
    cin >> x >> y;
    int a, b, ans = 0;
    for(int i = 0; i < n; ++i) {
        a = x[i] - '0';
        b = y[i] - '0';
        ans += min((a - b + 10) % 10, (b - a + 10) % 10 );
    }
    cout << ans << '\n';
    return 0;
}